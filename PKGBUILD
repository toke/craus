pkgname=craus
appname='kraus'
conflicts=(${appname})
provides=(${appname})
pkgver=1.4.12
pkgrel=0
pkgdesc='Kraus app'
arch=('i686' 'x86_64')
license=('Coffee ware')
makedepends=('cmake')
url="https://github.com/toke/craus"

#source=(git@github.com:toke/craus.git)

build() {
  #cd $srcdir/$appname-$pkgver
  mkdir -p build
  cd build
  cmake ../..
  make
}

package() {
  cd $srcdir/build
  make PREFIX=/usr DESTDIR="$pkgdir" install
  install -Dm644 ../../LICENSE "$pkgdir/usr/share/licenses/$appname/LICENSE"
  install -Dm644 ../../README.md "$pkgdir/usr/share/doc/$appname/README"
}

