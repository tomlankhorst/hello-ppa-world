Hello PPA World!
=====

A simple demo with everything in place to publish to Launchpad.

```
sudo apt-get install devscripts # dependencies

tar -acf hello-ppa-world_0.2.orig.tar.gz hello-ppa-world
cd hello-ppa-world
debuild -S -sa 
cd ..
dput ppa:tomlankhorst/ppa hello-ppa-world_0.2-0ppa0_source.changes
```
