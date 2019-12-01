pushd src/$1
node Day$1.bs.js || popd
popd