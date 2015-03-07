# K.R.A.U.S. in pure C

## Abstract

This is a portable C port of the famous K.R.A.U.S. (floor of the day) application by @jautz [written in perl](https://github.com/jautz/kraus).
The acronym K.R.A.U.S. stands for the German phrase "Kaffee-Runde auf unterschiedlichen Stockwerken".
It's origin lies far in the beginning of civilisation and was once called *Tempus clausum*.

Since being independent of a single implementation is cruical for live threatening services this fork
has been established.

[![Build Status](https://travis-ci.org/toke/craus.svg?branch=master)](https://travis-ci.org/toke/craus)

## Usage

`kraus -[p|j|v]c #`

List K.R.A.U.S. floor for current date. Optional parameters `-p`, `-j` and `-v`
are switching output to `plaintext`, `json` and `vcard`. The option `-c` followed
by a number instructs the program to output n concurrent days in specified format.

If no arguments are given the floor of the current day is printed on stdout.

### Example

`kraus -c 10` will print the floor of today and the next 9 days.

`kraus -v -c 10` same as above but in VCARD format.


## Implementation

Based on reverse engeneering the perl 5.6 srand() and rand() random number generators which are
basically calling the (System V/POSIX) random number generator seed48() and drand48() Pseudorandom
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

Dependencies: none

Build with:

```
mkdir build
cd build
cmake ..
make
sudo make install
```

or (create a debian package):

```
mkdir build
cd build
cmake ..
make
sudo checkinstall -D --pkgname=craus make install
```

or:



`gcc -o kraus kraus.c`


## Bugs

* This code is not multi-threading safe
* We have different time based problems. (Thanks John Titor for pointing this out) One of course obvious and final one is the end of our universe.
The code does not cope with this event and users should be aware of possible side effects. [[CITATION NEEDED](http://xkcd.com/285/)]

## Notes

The original author of K.R.A.U.S @jautz has used perl as it's language of choice (for very noble
reasons). I read the motto of perl in a different way. "There's more than one way to do it."
I saw this as my challenge.

**Fun fact:** the resulting code is just slightly smaller than the complete list of all possible values.
The compiled version is larger. But *sssshhh* this has to kept a secret.

**Pro Tip:** The command `kraus -c 365 | awk -- '{ print $2 "\tKRAUS " $8 }' > calendar` will generate a file that can be fed to the linux `calendar` program.

## References

* [Original K.R.A.U.S.](https://github.com/jautz/kraus)
* [drand48](http://pubs.opengroup.org/onlinepubs/007908799/xsh/drand48.html)
* [perl util.c](http://perl5.git.perl.org/perl.git/blob/HEAD:/util.c#l5563)
* [perl pp.c](http://perl5.git.perl.org/perl.git/blob/HEAD:/pp.c#l2700)
