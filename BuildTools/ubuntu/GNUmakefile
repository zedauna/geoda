ifndef GEODA_HOME
$(error You have to setup GEODA_HOME variable e.g. export GEODA_HOME=PWD, or run build.sh)
endif

include ../../GeoDamake.opt

GeoDa_OBJ = $(wildcard $(GeoDa_ROOT)/o/*.o)

default:	compile-geoda

app:  build-geoda

app18: build-geoda-1804

compile-geoda:	ogl-target io-target algorithms-target dataviewer-target dialogtools-target \
		weights-target knn-target explore-target libgdiam-target regression-target \
		shapeoperations-target resource-target varcalc-target \
		geoda-target

conf = `./libraries/bin/wx-config --libs`

test1:
	@echo test $(WX_HEADER) $(LIBS)

resource-target:
	(cd $(GeoDa_ROOT)/rc; $(MAKE) xrc; $(MAKE))

ogl-target:
	(cd $(GeoDa_ROOT)/ogl; $(MAKE))

weights-target:
	(cd $(GeoDa_ROOT)/Weights; $(MAKE))

knn-target:
	(cd $(GeoDa_ROOT)/kNN; $(MAKE))

io-target:
	(cd $(GeoDa_ROOT)/io; $(MAKE))

algorithms-target:
	(cd $(GeoDa_ROOT)/Algorithms; $(MAKE))

dataviewer-target:
	(cd $(GeoDa_ROOT)/DataViewer; $(MAKE))

dialogtools-target:
	(cd $(GeoDa_ROOT)/DialogTools; $(MAKE))

explore-target:
	(cd $(GeoDa_ROOT)/Explore; $(MAKE))

libgdiam-target:
	(cd $(GeoDa_ROOT)/libgdiam; $(MAKE))

regression-target:
	(cd $(GeoDa_ROOT)/Regression; $(MAKE))

shapeoperations-target:
	(cd $(GeoDa_ROOT)/ShapeOperations; $(MAKE))

varcalc-target:
	(cd $(GeoDa_ROOT)/VarCalc; $(MAKE))

geoda-target:
	(cd $(GeoDa_ROOT); $(MAKE))

build-geoda:
	rm -rf build
	mkdir -p build
	mkdir build/Resources
	mkdir build/gdaldata
	mkdir build/plugins
	mkdir build/basemap_cache
	mkdir build/web_plugins
	mkdir build/lang
	$(LD) $(LDFLAGS) $(GeoDa_OBJ) $(LIBS) -o build/GeoDa
	cp run.sh build/run.sh
	chmod +x build/run.sh
	cp -rf $(GeoDa_ROOT)/internationalization/lang/* build/lang
	cp $(GeoDa_ROOT)/rc/data_viewer_dialogs.xrc build/Resources
	cp $(GeoDa_ROOT)/rc/dialogs.xrc build/Resources
	cp $(GeoDa_ROOT)/rc/GeoDa.icns build/Resources
	cp $(GeoDa_ROOT)/rc/menus.xrc build/Resources
	cp $(GeoDa_ROOT)/rc/toolbar.xrc build/Resources
	cp $(GEODA_HOME)/libraries/lib/libgdal.so.20.0.0 build/plugins/libgdal.so.20
	cp $(GEODA_HOME)/libraries/lib/libkmldom.so.0.0.0 build/plugins/libkmldom.so.0
	cp $(GEODA_HOME)/libraries/lib/libkmlengine.so.0.0.0 build/plugins/libkmlengine.so.0
	cp $(GEODA_HOME)/libraries/lib/libkmlbase.so.0.0.0 build/plugins/libkmlbase.so.0
	cp $(GEODA_HOME)/libraries/lib/libxerces-c-3.1.so build/plugins/libxerces-c-3.1.so
	cp $(GEODA_HOME)/libraries/lib/libspatialite.so.5.0.1 build/plugins/libspatialite.so.5
	cp $(GEODA_HOME)/libraries/lib/libfreexl.so.1.0.0 build/plugins/libfreexl.so.1
	cp $(GEODA_HOME)/libraries/lib/libproj.so.0.7.0 build/plugins/libproj.so.0
	cp $(GEODA_HOME)/libraries/lib/libgeos_c.so.1.10.2 build/plugins/libgeos_c.so.1
	cp $(GEODA_HOME)/libraries/lib/libsqlite3.so.0.8.6 build/plugins/libsqlite3.so.0
	cp $(GEODA_HOME)/libraries/lib/libiconv.so.2.5.0 build/plugins/libiconv.so.2
	chmod +x build/plugins/libiconv.so.2
	cp $(GEODA_HOME)/libraries/lib/libminizip.so.0.0.0 build/plugins/libminizip.so.0
	cp $(GEODA_HOME)/libraries/lib/liburiparser.so.1.0.5 build/plugins/liburiparser.so.1
	cp $(GEODA_HOME)/libraries/lib/libgeos-3.6.2.so build/plugins/libgeos-3.6.2.so
	cp $(GEODA_HOME)/libraries/lib/libcurl.so.4.5.0 build/plugins/libcurl.so.4
	cp $(GEODA_HOME)/libraries/lib/libcares.so.2.1.0 build/plugins/libcares.so.2
	cp $(GEODA_HOME)/libraries/share/gdal/* build/gdaldata
	cp $(GEODA_HOME)/../CommonDistFiles/cache.sqlite build/cache.sqlite
	cp $(GEODA_HOME)/../CommonDistFiles/geoda_prefs.sqlite build/geoda_prefs.sqlite
	cp $(GEODA_HOME)/../CommonDistFiles/geoda_prefs.json build/geoda_prefs.json
	cp -rf $(GEODA_HOME)/../CommonDistFiles/web_plugins/* build/web_plugins
	cp -rf $(GeoDa_ROOT)/internationalization/lang build/

build-geoda-1804:
	rm -rf build
	mkdir -p build
	mkdir build/Resources
	mkdir build/gdaldata
	mkdir build/plugins
	mkdir build/basemap_cache
	mkdir build/web_plugins
	$(LD) $(LDFLAGS) $(GeoDa_OBJ) $(LIBS) -o build/GeoDa
	cp run.sh build/run.sh
	chmod +x build/run.sh
	cp $(GeoDa_ROOT)/rc/data_viewer_dialogs.xrc build/Resources
	cp $(GeoDa_ROOT)/rc/dialogs.xrc build/Resources
	cp $(GeoDa_ROOT)/rc/GeoDa.icns build/Resources
	cp $(GeoDa_ROOT)/rc/menus.xrc build/Resources
	cp $(GeoDa_ROOT)/rc/toolbar.xrc build/Resources
	cp $(GEODA_HOME)/libraries/lib/libcares.so.2.1.0 build/plugins/libcares.so.2
	cp /usr/share/gdal/2.2/* build/gdaldata
	cp $(GEODA_HOME)/../CommonDistFiles/cache.sqlite build/cache.sqlite
	cp $(GEODA_HOME)/../CommonDistFiles/geoda_prefs.sqlite build/geoda_prefs.sqlite
	cp $(GEODA_HOME)/../CommonDistFiles/geoda_prefs.json build/geoda_prefs.json
	cp -rf $(GEODA_HOME)/../CommonDistFiles/web_plugins/* build/web_plugins
	cp -rf $(GeoDa_ROOT)/internationalization/lang build/

clean:
	rm -f ../../o/*
	rm -rf build
