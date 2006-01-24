"""
Angular separation between two Positions.

Can be defined by hand, or produced by "subtracting" two positions.
Like L{position.Position}, it will have an internal representation,
and a variety of user-selected representations.

@author: Vicki Laidler

"""

import math

class AngSep:
    """
    The AngSep class lets the user compare the angular separation between different L{position.Position}s without having to think too much about units.

    Each AngSep object is created with a particular length in a particular set of units. These are then converted into an internal representation which is used for all math and comparisons.

    All unit checks are performed by checking the first few letters of the unit string, to provide more flexibility for the user. (eg, "arc" "arcs" "arcsec" "arcseconds" will all evaluate to arcseconds.)
    
    All math and comparisons can be done either between two AngSep objects, or between an AngSep object and a number. In the latter case, the number is assumed to have the same units as the AngSep object.

    Example:
    ========
    
    >>> #Default units are arcsec
    >>> a=angsep.AngSep(5)
    >>> a
    5.000000 arcsec
    >>> #The usual arithmetic works
    >>> b=angsep.AngSep(3)
    >>> a+b
    8.000000 arcsec
    >>> a*3
    15.000000 arcsec

    >>> #Use AngSep together with Position
    >>> p1=P.Position('12:34:45.23 45:43:21.12')
    >>> p2=P.Position('12:34:47.34 45:43:23.0')
    >>> sep=p1.angsep(p2)
    >>> eps=angsep.AngSep(30,units='arcsec')
    >>> p1.within(p2,eps)
    True
    >>> p2.within(p1,20)
    False

    @note: Angular Separations are inherently positive: negative separations have no physical meaning, and are forbidden.

    @ivar value: magnitude of the angular separation
    @type value: number
    @ivar units: units in which the magnitude is expressed (arcsec, degrees, or radians)
    @type units: string
    @ivar _internal: internal representation of the separation
    @type _internal: number (degrees)

    """
    def __init__(self,value,units='arcsec'):
        """
        @param value: magnitude of the angular separation
        @type value: number
        @param units: arcsec or degrees
        @type units: string

        @rtype: AngSep

        @raise ValueError: if value < 0. Negative separations are physically meaningless and thus forbidden. 
        """
        if (value < 0):
            raise ValueError, "Separations must be nonnegative: %f < 0"%value
        self.value=value
        self.units=units.lower()
        if units.startswith('deg'):
            self._internal=self.value
        else:
            self._calcinternal()

    def __repr__(self):
        """ @rtype: string """
        return "%f %s"%(self.value,self.units)

    def _calcinternal(self):
        """ Sets the internal representation
        @raise ValueError: if units are not rad|arcsec|degrees

        @rtype: None
        """
        if self.units.startswith('rad'):
            self._internal=(self.value/math.pi)*180.0
        elif self.units.startswith('arcs'):
            self._internal=self.value/3600.0
        elif self.units.startswith('deg'):
            pass
        else:
            raise ValueError,"Invalid units: %s"%self.units
        
    def setunits(self,units):
        """ Sets the units of the public representation, and converts the publically visible value to those units

        @param units: radians, arcsec, or degrees
        @type units: string

        @rtype: None
        """
        
        if units.startswith('rad'):
            self.value=(self._internal*math.pi)/180.0
        elif units.startswith('arcs'):
            self.value=self._internal*3600.0
        elif units.startswith('deg'):
            self.value=self._internal
        self.units=units

    def __gt__(self, other):
        if isinstance(other,AngSep):
#            print "%f > %f"%(self._internal,other._internal)
            return self._internal > other._internal
        else:
#            print "%f > %f"%(self.value,other)
            return self.value > other

    def __ge__(self,other):
        ans = (self > other) or (self == other)
        return ans
    
    def __lt__(self, other):
        if isinstance(other,AngSep):
             return self._internal < other._internal
        else:
             return self.value < other

    def __le__(self,other):
        ans = (self < other) or (self == other)
        return ans
  
    def __eq__(self,other):
        if isinstance(other,AngSep):
            return self._internal == other._internal
        else:
            return self.value == other

    def __ne__(self,other):
        if isinstance(other,AngSep):
            return self._internal != other._internal
        else:
            return self.value != other

    def __add__(self,other):
        if isinstance(other,AngSep):
            myunits=self.units
            ans=AngSep(self._internal + other._internal,units='degrees')
            ans.setunits(myunits)
        else:
            ans=AngSep(self.value+other,units=self.units)
        return ans

    def __sub__(self,other):
        if isinstance(other,AngSep):
            myunits=self.units
            ans=AngSep(self._internal - other._internal,units='degrees')
            ans.setunits(myunits)
        else:
            ans=AngSep(self.value-other,units=self.units)
        return ans
    
    def __mul__(self,other):
        if isinstance(other,AngSep):
            myunits=self.units
            ans=AngSep(self._internal*other._internal,units='degrees')
            ans.setunits(myunits)
        else:
            ans=AngSep(self.value * other,units=self.units)
        return ans
    
    def __rmul__(self,other):
        return self*other
    
    def __rsub__(self,other):
        ans = -1*(self) + other 
        return ans
    
    def __radd__(self,other):
        ans = self + other
        return ans
    
            
        
            

    def approx(self,other,epsilon):
        """ True if "self" and "other" are equal to within "epsilon". "epsilon"  is considered to have the same units as self.

        @note: This is not implemented as 'abs(self-other)<epsilon' because of the prohibition on negative separations.

        @type other: AngSep or number (units of self)
        @type epsilon: AngSep or number (units of self)
        

        @rtype: Boolean

        """
        #Handle issues of epsilon units
        if isinstance(epsilon,AngSep):
            eps=epsilon
        else:
            eps=AngSep(epsilon,units=self.units)

        #Compare internal units if other is an AngSep;
        #self units if other is a number
        if isinstance(other,AngSep):
            ans=abs(self._internal-other._internal) <= eps._internal
        else:
            ans=abs(self.value-other) <= eps.value
            
        return ans
    
    ###Ok. at this point either:
    # - define the abs() function,
    #       which intrinsically permits the notion of negative separations
    # or,
    # - enforce positive values only:
    #     - test & raise exception in init, subtraction
    #     - define approx with a try/except
    #
    #
    # but there's a bigger problem. What are the units of epsilon?
    #
    
    def arcsec(self):
        """ @return: separation in arcsec
            @rtype: float """
        return self._internal*3600.0

    def radians(self):
        """ @return: separation in radians
            @rtype: float """
        return self._internal*180.0/math.pi

    def degrees(self):
        """ @return: separation in degrees
            @rtype: float """
        return self._internal
