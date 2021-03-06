# K.R.A.U.S. in pure C

## Abstract

This is a C port of the famous K.R.A.U.S. (floor of the day) application by @jautz [written in perl](https://github.com/jautz/kraus).
The acronym K.R.A.U.S. stands for the German phrase "Kaffee-Runde auf unterschiedlichen Stockwerken".
It's origin lies far in the beginning of civilisation and was once called *Tempus clausum*.

Since being independent of a single implementation is crucial for live threatening services this fork
has been established.

[![Build Status](https://travis-ci.org/toke/craus.svg?branch=master)](https://travis-ci.org/toke/craus)

## Usage

`kraus [-h] [-w] [-o output] [-s strategy] [-c count] `

List K.R.A.U.S. floor for the current date. Valid values for the -o parameter are
`csv`, `text`, `simple`, `json`, `calendar` and `vcard`. The option `-c` followed
by a number instructs the program to output n concurrent days in specified format.
The option `-w` suppress output of weekends.

If no arguments are given the floor of the current day is printed on stdout.

### Example

`kraus -c 10` will print the floor of today and the next 9 days.

`kraus -o vcard -c 10` same as above but in VCARD format.


## Implementation

Based on reverse engeneering the perl 5.6 srand() and rand() random number generators which are
basically calling the (System V/POSIX) random number generator seed48() and drand48() pseudo random
Functions (at least in our use case).

This is how perl initializes the seed value (in our case):

`unsigned short seed[3] = {0x330e,perl_seed[0],perl_seed[1]};`

According to [man drand48 (3)](http://man7.org/linux/man-pages/man3/drand48.3.html) seed48 generates:
> …a sequence of 48-bit integers, Xi, according to the linear congruential formula:
> `Xn+1 = (aXn + c) mod m, where n >= 0`
> The parameter m = 2^48, hence 48-bit integer arithmetic is performed.

While drand48:

> The drand48() and erand48() functions return nonnegative double-
> precision floating-point values uniformly distributed between [0.0,
> 1.0)

## Installation

### Dependencies:

libcurl when build with jautz strategy module.

To build without curl and jautz support use `-DMOD_STRATEGY_JAUTZ:boolean=off`
as cmake parameter.

### Build with:

```
mkdir build
cd build
cmake ..
make
sudo make install
```

### Create a Debian package

```debuild -i -us -uc -b```

or

```cpack  -G DEB```

or

```
mkdir build
cd build
cmake ..
make
sudo checkinstall -D --pkgname=craus make install
```

## Bugs

* This code is not multi-threading safe
* The jautz Strategy only supports the current day and no delte
* We have different time based problems. (Thanks John Titor for pointing this out) One of course obvious and final one is the end of our universe.
The code does not cope with this event and users should be aware of possible side effects. [[CITATION NEEDED](http://xkcd.com/285/)]

## Notes

The original author of K.R.A.U.S @jautz has used perl as it's language of choice (for very noble
reasons). I read the motto of perl in a different way. "There's more than one way to do it."
I saw this as my challenge.

**Fun fact:** the resulting code is just slightly smaller than the complete list of all possible values.
The compiled version is larger (of the original simple Version). But *sssshhh* this has to kept a secret.

**Pro Tip:** The command `kraus -c 365 | awk -- '{ print $2 "\tKRAUS " $8 }' > calendar` will generate a file that can be fed to the linux `calendar` program.

This is a Toy-Project and subject of several overengeneerings and experiments.

## Contact

Contact: Thomas Kerpe [toke@toke.de](mailto:toke@toke.de)

OpenPGP fingerprint: `B5AD 7FCB 270D A762 46D2  A8F2 B0E6 5607 ABE5 7238`

## References

* [Original K.R.A.U.S.](https://github.com/jautz/kraus)
* [drand48](http://pubs.opengroup.org/onlinepubs/007908799/xsh/drand48.html)
* [perl util.c](http://perl5.git.perl.org/perl.git/blob/HEAD:/util.c#l5563)
* [perl pp.c](http://perl5.git.perl.org/perl.git/blob/HEAD:/pp.c#l2700)
* [man calendar](http://linux.die.net/man/1/calendar)
