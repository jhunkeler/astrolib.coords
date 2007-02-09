"""
Package: AstroLib Coords

Purpose
=======

This package aims to provide much of the IDL "astron" functionality that
pertains to coordinate manipulations in an OO framework. Our target user is
a typical astronomer who needs to analyze data, work with catalogs, prepare
observing proposals, and prepare for observing runs.

The initial version will provide simple functionality for working with
positions in the same reference frame, without having to worry about units.



Dependencies
============
numarray

pytpm -- a Python wrapper for the TPM library graciously contributed
by Jeff Percival

Example
=======

>>> import coords as C
#
#Unit conversions
>>> ob=C.Position('12:34:45.34 -23:42:32.6')
>>> ob.hmsdms()
'12:34:45.340 -23:42:32.600'
>>> ob.dd()
(188.68891666666667, -23.709055555555555)
>>> ob.rad()
(3.2932428578545374, -0.41380108198269777)
#
#Angular separations
>>> p1=C.Position("01:23:45.300 +65:43:31.240")
>>> p2=C.Position("01:23:45.62 +65:43:31.20")
>>> p1.angsep(p2)
0.000548 degrees
>>> delta=p1.angsep(p2)
>>> delta.arcsec()
1.973739377865491
>>> p1.within(p2,3.0,units='arcsec')
True
#
# Coordinate conversions
>>> ob.j2000()
(188.68891666666667, -23.709055555555555)
>>> ob.b1950()
(188.03056480942405, -23.433637283819877)
>>> ob.galactic()
(298.01638938748795, 39.003358150874568)
>>> ob.ecliptic()
(197.58457414028533, -18.294241465720475)




For more examples, see the wiki page listed below.

TPM Citation
============
Investigators using this software for their research are requested to
explicitly acknowledge "use of the TPM software library, by Jeffrey W.
Percival" in any appropriate publications. 

@sort: Position, Coord, Degrees, Hmsdms


@see: U{http://www.scipy.org/AstroLibCoordsHome}

@author:  Vicki Laidler
@version: '0.3 (2007-2-??)'



@group Classes: position.Position, position.Coord, angsep.Angsep
@group Modules: position, angsep
@sort: Classes, Modules

@sort: position, angsep
"""
from position import Position
from angsep import AngSep
from astrodate import AstroDate


__version__ = '0.3'      #Release version number only
__vdate__ = '2007-2-??'   #Date of this version, in this (FITS-style) format

def _test():
    import doctest
    import test_snapshot
    doctest.testmod(test_snapshot)
