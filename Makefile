#------------------------------------------------------------------------------#
# This makefile was generated by 'cbp2make' tool rev.147                       #
#------------------------------------------------------------------------------#


WORKDIR = `pwd`

CC = mpiicpc
CXX = mpiicpc
AR = ar
LD = mpiicpc
WINDRES = windres

INC = -Isrc/
CFLAGS = -Wall -fexceptions -std=c++11
RESINC = 
LIBDIR = -Llib/
LIB = -lfreeimage
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/RayTracer

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/RayTracer

OBJ_DEBUG = $(OBJDIR_DEBUG)/src/lights/arealight.o $(OBJDIR_DEBUG)/src/lights/ambient_occluder.o $(OBJDIR_DEBUG)/src/lights/ambient.o $(OBJDIR_DEBUG)/src/light.o $(OBJDIR_DEBUG)/src/lights/directional.o $(OBJDIR_DEBUG)/src/materials/reflective.o $(OBJDIR_DEBUG)/src/materials/phong.o $(OBJDIR_DEBUG)/src/materials/matte.o $(OBJDIR_DEBUG)/src/materials/glossy_reflector.o $(OBJDIR_DEBUG)/src/materials/emissive.o $(OBJDIR_DEBUG)/src/material.o $(OBJDIR_DEBUG)/src/lights/pointlight.o $(OBJDIR_DEBUG)/src/tinyxml/tinystr.o $(OBJDIR_DEBUG)/src/texture.o $(OBJDIR_DEBUG)/src/serializable.o $(OBJDIR_DEBUG)/src/scheduler.o $(OBJDIR_DEBUG)/src/tinyxml/tinyxml.o $(OBJDIR_DEBUG)/src/scene_parser.o $(OBJDIR_DEBUG)/src/samplers/regular.o $(OBJDIR_DEBUG)/src/samplers/multi_jittered.o $(OBJDIR_DEBUG)/src/world.o $(OBJDIR_DEBUG)/src/viewplane.o $(OBJDIR_DEBUG)/src/tracers/whitted.o $(OBJDIR_DEBUG)/src/tracers/tracer.o $(OBJDIR_DEBUG)/src/sampler.o $(OBJDIR_DEBUG)/src/tracers/raycast.o $(OBJDIR_DEBUG)/src/tracers/area_lighting.o $(OBJDIR_DEBUG)/src/tinyxml/tinyxmlparser.o $(OBJDIR_DEBUG)/src/tinyxml/tinyxmlerror.o $(OBJDIR_DEBUG)/src/objects/compound.o $(OBJDIR_DEBUG)/src/objects/instance.o $(OBJDIR_DEBUG)/src/objects/grid.o $(OBJDIR_DEBUG)/src/objects/flat_mesh_triangle.o $(OBJDIR_DEBUG)/src/objects/disk.o $(OBJDIR_DEBUG)/src/object.o $(OBJDIR_DEBUG)/src/mymath.o $(OBJDIR_DEBUG)/src/mesh_triangle.o $(OBJDIR_DEBUG)/src/objects/plane.o $(OBJDIR_DEBUG)/src/objects/smooth_mesh_triangle.o $(OBJDIR_DEBUG)/src/objects/sphere.o $(OBJDIR_DEBUG)/src/objects/triangle.o $(OBJDIR_DEBUG)/src/objects/triangle_mesh.o $(OBJDIR_DEBUG)/src/ply.o $(OBJDIR_DEBUG)/src/glm/detail/glm.o $(OBJDIR_DEBUG)/src/glm/detail/dummy.o $(OBJDIR_DEBUG)/src/bbox.o $(OBJDIR_DEBUG)/src/brdfs/perfect_specular.o $(OBJDIR_DEBUG)/src/brdfs/lambertian.o $(OBJDIR_DEBUG)/src/brdfs/glossy_specular.o $(OBJDIR_DEBUG)/src/backgrounds/sphere_sky.o $(OBJDIR_DEBUG)/src/backgrounds/single_color.o $(OBJDIR_DEBUG)/src/background.o $(OBJDIR_DEBUG)/src/camera.o $(OBJDIR_DEBUG)/src/cameras/pinhole.o $(OBJDIR_DEBUG)/src/cameras/thinlens.o $(OBJDIR_DEBUG)/src/datastore.o $(OBJDIR_DEBUG)/main.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/src/lights/arealight.o $(OBJDIR_RELEASE)/src/lights/ambient_occluder.o $(OBJDIR_RELEASE)/src/lights/ambient.o $(OBJDIR_RELEASE)/src/light.o $(OBJDIR_RELEASE)/src/lights/directional.o $(OBJDIR_RELEASE)/src/materials/reflective.o $(OBJDIR_RELEASE)/src/materials/phong.o $(OBJDIR_RELEASE)/src/materials/matte.o $(OBJDIR_RELEASE)/src/materials/glossy_reflector.o $(OBJDIR_RELEASE)/src/materials/emissive.o $(OBJDIR_RELEASE)/src/material.o $(OBJDIR_RELEASE)/src/lights/pointlight.o $(OBJDIR_RELEASE)/src/tinyxml/tinystr.o $(OBJDIR_RELEASE)/src/texture.o $(OBJDIR_RELEASE)/src/serializable.o $(OBJDIR_RELEASE)/src/scheduler.o $(OBJDIR_RELEASE)/src/tinyxml/tinyxml.o $(OBJDIR_RELEASE)/src/scene_parser.o $(OBJDIR_RELEASE)/src/samplers/regular.o $(OBJDIR_RELEASE)/src/samplers/multi_jittered.o $(OBJDIR_RELEASE)/src/world.o $(OBJDIR_RELEASE)/src/viewplane.o $(OBJDIR_RELEASE)/src/tracers/whitted.o $(OBJDIR_RELEASE)/src/tracers/tracer.o $(OBJDIR_RELEASE)/src/sampler.o $(OBJDIR_RELEASE)/src/tracers/raycast.o $(OBJDIR_RELEASE)/src/tracers/area_lighting.o $(OBJDIR_RELEASE)/src/tinyxml/tinyxmlparser.o $(OBJDIR_RELEASE)/src/tinyxml/tinyxmlerror.o $(OBJDIR_RELEASE)/src/objects/compound.o $(OBJDIR_RELEASE)/src/objects/instance.o $(OBJDIR_RELEASE)/src/objects/grid.o $(OBJDIR_RELEASE)/src/objects/flat_mesh_triangle.o $(OBJDIR_RELEASE)/src/objects/disk.o $(OBJDIR_RELEASE)/src/object.o $(OBJDIR_RELEASE)/src/mymath.o $(OBJDIR_RELEASE)/src/mesh_triangle.o $(OBJDIR_RELEASE)/src/objects/plane.o $(OBJDIR_RELEASE)/src/objects/smooth_mesh_triangle.o $(OBJDIR_RELEASE)/src/objects/sphere.o $(OBJDIR_RELEASE)/src/objects/triangle.o $(OBJDIR_RELEASE)/src/objects/triangle_mesh.o $(OBJDIR_RELEASE)/src/ply.o $(OBJDIR_RELEASE)/src/glm/detail/glm.o $(OBJDIR_RELEASE)/src/glm/detail/dummy.o $(OBJDIR_RELEASE)/src/bbox.o $(OBJDIR_RELEASE)/src/brdfs/perfect_specular.o $(OBJDIR_RELEASE)/src/brdfs/lambertian.o $(OBJDIR_RELEASE)/src/brdfs/glossy_specular.o $(OBJDIR_RELEASE)/src/backgrounds/sphere_sky.o $(OBJDIR_RELEASE)/src/backgrounds/single_color.o $(OBJDIR_RELEASE)/src/background.o $(OBJDIR_RELEASE)/src/camera.o $(OBJDIR_RELEASE)/src/cameras/pinhole.o $(OBJDIR_RELEASE)/src/cameras/thinlens.o $(OBJDIR_RELEASE)/src/datastore.o $(OBJDIR_RELEASE)/main.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG)/src/lights || mkdir -p $(OBJDIR_DEBUG)/src/lights
	test -d $(OBJDIR_DEBUG)/src || mkdir -p $(OBJDIR_DEBUG)/src
	test -d $(OBJDIR_DEBUG)/src/materials || mkdir -p $(OBJDIR_DEBUG)/src/materials
	test -d $(OBJDIR_DEBUG)/src/tinyxml || mkdir -p $(OBJDIR_DEBUG)/src/tinyxml
	test -d $(OBJDIR_DEBUG)/src/samplers || mkdir -p $(OBJDIR_DEBUG)/src/samplers
	test -d $(OBJDIR_DEBUG)/src/tracers || mkdir -p $(OBJDIR_DEBUG)/src/tracers
	test -d $(OBJDIR_DEBUG)/src/objects || mkdir -p $(OBJDIR_DEBUG)/src/objects
	test -d $(OBJDIR_DEBUG)/src/glm/detail || mkdir -p $(OBJDIR_DEBUG)/src/glm/detail
	test -d $(OBJDIR_DEBUG)/src/brdfs || mkdir -p $(OBJDIR_DEBUG)/src/brdfs
	test -d $(OBJDIR_DEBUG)/src/backgrounds || mkdir -p $(OBJDIR_DEBUG)/src/backgrounds
	test -d $(OBJDIR_DEBUG)/src/cameras || mkdir -p $(OBJDIR_DEBUG)/src/cameras
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/src/lights/arealight.o: src/lights/arealight.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/lights/arealight.cpp -o $(OBJDIR_DEBUG)/src/lights/arealight.o

$(OBJDIR_DEBUG)/src/lights/ambient_occluder.o: src/lights/ambient_occluder.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/lights/ambient_occluder.cpp -o $(OBJDIR_DEBUG)/src/lights/ambient_occluder.o

$(OBJDIR_DEBUG)/src/lights/ambient.o: src/lights/ambient.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/lights/ambient.cpp -o $(OBJDIR_DEBUG)/src/lights/ambient.o

$(OBJDIR_DEBUG)/src/light.o: src/light.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/light.cpp -o $(OBJDIR_DEBUG)/src/light.o

$(OBJDIR_DEBUG)/src/lights/directional.o: src/lights/directional.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/lights/directional.cpp -o $(OBJDIR_DEBUG)/src/lights/directional.o

$(OBJDIR_DEBUG)/src/materials/reflective.o: src/materials/reflective.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/materials/reflective.cpp -o $(OBJDIR_DEBUG)/src/materials/reflective.o

$(OBJDIR_DEBUG)/src/materials/phong.o: src/materials/phong.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/materials/phong.cpp -o $(OBJDIR_DEBUG)/src/materials/phong.o

$(OBJDIR_DEBUG)/src/materials/matte.o: src/materials/matte.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/materials/matte.cpp -o $(OBJDIR_DEBUG)/src/materials/matte.o

$(OBJDIR_DEBUG)/src/materials/glossy_reflector.o: src/materials/glossy_reflector.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/materials/glossy_reflector.cpp -o $(OBJDIR_DEBUG)/src/materials/glossy_reflector.o

$(OBJDIR_DEBUG)/src/materials/emissive.o: src/materials/emissive.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/materials/emissive.cpp -o $(OBJDIR_DEBUG)/src/materials/emissive.o

$(OBJDIR_DEBUG)/src/material.o: src/material.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/material.cpp -o $(OBJDIR_DEBUG)/src/material.o

$(OBJDIR_DEBUG)/src/lights/pointlight.o: src/lights/pointlight.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/lights/pointlight.cpp -o $(OBJDIR_DEBUG)/src/lights/pointlight.o

$(OBJDIR_DEBUG)/src/tinyxml/tinystr.o: src/tinyxml/tinystr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/tinyxml/tinystr.cpp -o $(OBJDIR_DEBUG)/src/tinyxml/tinystr.o

$(OBJDIR_DEBUG)/src/texture.o: src/texture.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/texture.cpp -o $(OBJDIR_DEBUG)/src/texture.o

$(OBJDIR_DEBUG)/src/serializable.o: src/serializable.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/serializable.cpp -o $(OBJDIR_DEBUG)/src/serializable.o

$(OBJDIR_DEBUG)/src/scheduler.o: src/scheduler.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/scheduler.cpp -o $(OBJDIR_DEBUG)/src/scheduler.o

$(OBJDIR_DEBUG)/src/tinyxml/tinyxml.o: src/tinyxml/tinyxml.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/tinyxml/tinyxml.cpp -o $(OBJDIR_DEBUG)/src/tinyxml/tinyxml.o

$(OBJDIR_DEBUG)/src/scene_parser.o: src/scene_parser.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/scene_parser.cpp -o $(OBJDIR_DEBUG)/src/scene_parser.o

$(OBJDIR_DEBUG)/src/samplers/regular.o: src/samplers/regular.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/samplers/regular.cpp -o $(OBJDIR_DEBUG)/src/samplers/regular.o

$(OBJDIR_DEBUG)/src/samplers/multi_jittered.o: src/samplers/multi_jittered.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/samplers/multi_jittered.cpp -o $(OBJDIR_DEBUG)/src/samplers/multi_jittered.o

$(OBJDIR_DEBUG)/src/world.o: src/world.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/world.cpp -o $(OBJDIR_DEBUG)/src/world.o

$(OBJDIR_DEBUG)/src/viewplane.o: src/viewplane.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/viewplane.cpp -o $(OBJDIR_DEBUG)/src/viewplane.o

$(OBJDIR_DEBUG)/src/tracers/whitted.o: src/tracers/whitted.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/tracers/whitted.cpp -o $(OBJDIR_DEBUG)/src/tracers/whitted.o

$(OBJDIR_DEBUG)/src/tracers/tracer.o: src/tracers/tracer.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/tracers/tracer.cpp -o $(OBJDIR_DEBUG)/src/tracers/tracer.o

$(OBJDIR_DEBUG)/src/sampler.o: src/sampler.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/sampler.cpp -o $(OBJDIR_DEBUG)/src/sampler.o

$(OBJDIR_DEBUG)/src/tracers/raycast.o: src/tracers/raycast.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/tracers/raycast.cpp -o $(OBJDIR_DEBUG)/src/tracers/raycast.o

$(OBJDIR_DEBUG)/src/tracers/area_lighting.o: src/tracers/area_lighting.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/tracers/area_lighting.cpp -o $(OBJDIR_DEBUG)/src/tracers/area_lighting.o

$(OBJDIR_DEBUG)/src/tinyxml/tinyxmlparser.o: src/tinyxml/tinyxmlparser.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/tinyxml/tinyxmlparser.cpp -o $(OBJDIR_DEBUG)/src/tinyxml/tinyxmlparser.o

$(OBJDIR_DEBUG)/src/tinyxml/tinyxmlerror.o: src/tinyxml/tinyxmlerror.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/tinyxml/tinyxmlerror.cpp -o $(OBJDIR_DEBUG)/src/tinyxml/tinyxmlerror.o

$(OBJDIR_DEBUG)/src/objects/compound.o: src/objects/compound.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/objects/compound.cpp -o $(OBJDIR_DEBUG)/src/objects/compound.o

$(OBJDIR_DEBUG)/src/objects/instance.o: src/objects/instance.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/objects/instance.cpp -o $(OBJDIR_DEBUG)/src/objects/instance.o

$(OBJDIR_DEBUG)/src/objects/grid.o: src/objects/grid.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/objects/grid.cpp -o $(OBJDIR_DEBUG)/src/objects/grid.o

$(OBJDIR_DEBUG)/src/objects/flat_mesh_triangle.o: src/objects/flat_mesh_triangle.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/objects/flat_mesh_triangle.cpp -o $(OBJDIR_DEBUG)/src/objects/flat_mesh_triangle.o

$(OBJDIR_DEBUG)/src/objects/disk.o: src/objects/disk.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/objects/disk.cpp -o $(OBJDIR_DEBUG)/src/objects/disk.o

$(OBJDIR_DEBUG)/src/object.o: src/object.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/object.cpp -o $(OBJDIR_DEBUG)/src/object.o

$(OBJDIR_DEBUG)/src/mymath.o: src/mymath.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/mymath.cpp -o $(OBJDIR_DEBUG)/src/mymath.o

$(OBJDIR_DEBUG)/src/mesh_triangle.o: src/mesh_triangle.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/mesh_triangle.cpp -o $(OBJDIR_DEBUG)/src/mesh_triangle.o

$(OBJDIR_DEBUG)/src/objects/plane.o: src/objects/plane.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/objects/plane.cpp -o $(OBJDIR_DEBUG)/src/objects/plane.o

$(OBJDIR_DEBUG)/src/objects/smooth_mesh_triangle.o: src/objects/smooth_mesh_triangle.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/objects/smooth_mesh_triangle.cpp -o $(OBJDIR_DEBUG)/src/objects/smooth_mesh_triangle.o

$(OBJDIR_DEBUG)/src/objects/sphere.o: src/objects/sphere.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/objects/sphere.cpp -o $(OBJDIR_DEBUG)/src/objects/sphere.o

$(OBJDIR_DEBUG)/src/objects/triangle.o: src/objects/triangle.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/objects/triangle.cpp -o $(OBJDIR_DEBUG)/src/objects/triangle.o

$(OBJDIR_DEBUG)/src/objects/triangle_mesh.o: src/objects/triangle_mesh.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/objects/triangle_mesh.cpp -o $(OBJDIR_DEBUG)/src/objects/triangle_mesh.o

$(OBJDIR_DEBUG)/src/ply.o: src/ply.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/ply.c -o $(OBJDIR_DEBUG)/src/ply.o

$(OBJDIR_DEBUG)/src/glm/detail/glm.o: src/glm/detail/glm.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/glm/detail/glm.cpp -o $(OBJDIR_DEBUG)/src/glm/detail/glm.o

$(OBJDIR_DEBUG)/src/glm/detail/dummy.o: src/glm/detail/dummy.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/glm/detail/dummy.cpp -o $(OBJDIR_DEBUG)/src/glm/detail/dummy.o

$(OBJDIR_DEBUG)/src/bbox.o: src/bbox.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/bbox.cpp -o $(OBJDIR_DEBUG)/src/bbox.o

$(OBJDIR_DEBUG)/src/brdfs/perfect_specular.o: src/brdfs/perfect_specular.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/brdfs/perfect_specular.cpp -o $(OBJDIR_DEBUG)/src/brdfs/perfect_specular.o

$(OBJDIR_DEBUG)/src/brdfs/lambertian.o: src/brdfs/lambertian.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/brdfs/lambertian.cpp -o $(OBJDIR_DEBUG)/src/brdfs/lambertian.o

$(OBJDIR_DEBUG)/src/brdfs/glossy_specular.o: src/brdfs/glossy_specular.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/brdfs/glossy_specular.cpp -o $(OBJDIR_DEBUG)/src/brdfs/glossy_specular.o

$(OBJDIR_DEBUG)/src/backgrounds/sphere_sky.o: src/backgrounds/sphere_sky.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/backgrounds/sphere_sky.cpp -o $(OBJDIR_DEBUG)/src/backgrounds/sphere_sky.o

$(OBJDIR_DEBUG)/src/backgrounds/single_color.o: src/backgrounds/single_color.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/backgrounds/single_color.cpp -o $(OBJDIR_DEBUG)/src/backgrounds/single_color.o

$(OBJDIR_DEBUG)/src/background.o: src/background.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/background.cpp -o $(OBJDIR_DEBUG)/src/background.o

$(OBJDIR_DEBUG)/src/camera.o: src/camera.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/camera.cpp -o $(OBJDIR_DEBUG)/src/camera.o

$(OBJDIR_DEBUG)/src/cameras/pinhole.o: src/cameras/pinhole.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/cameras/pinhole.cpp -o $(OBJDIR_DEBUG)/src/cameras/pinhole.o

$(OBJDIR_DEBUG)/src/cameras/thinlens.o: src/cameras/thinlens.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/cameras/thinlens.cpp -o $(OBJDIR_DEBUG)/src/cameras/thinlens.o

$(OBJDIR_DEBUG)/src/datastore.o: src/datastore.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src/datastore.cpp -o $(OBJDIR_DEBUG)/src/datastore.o

$(OBJDIR_DEBUG)/main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)/main.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)/src/lights
	rm -rf $(OBJDIR_DEBUG)/src
	rm -rf $(OBJDIR_DEBUG)/src/materials
	rm -rf $(OBJDIR_DEBUG)/src/tinyxml
	rm -rf $(OBJDIR_DEBUG)/src/samplers
	rm -rf $(OBJDIR_DEBUG)/src/tracers
	rm -rf $(OBJDIR_DEBUG)/src/objects
	rm -rf $(OBJDIR_DEBUG)/src/glm/detail
	rm -rf $(OBJDIR_DEBUG)/src/brdfs
	rm -rf $(OBJDIR_DEBUG)/src/backgrounds
	rm -rf $(OBJDIR_DEBUG)/src/cameras
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE)/src/lights || mkdir -p $(OBJDIR_RELEASE)/src/lights
	test -d $(OBJDIR_RELEASE)/src || mkdir -p $(OBJDIR_RELEASE)/src
	test -d $(OBJDIR_RELEASE)/src/materials || mkdir -p $(OBJDIR_RELEASE)/src/materials
	test -d $(OBJDIR_RELEASE)/src/tinyxml || mkdir -p $(OBJDIR_RELEASE)/src/tinyxml
	test -d $(OBJDIR_RELEASE)/src/samplers || mkdir -p $(OBJDIR_RELEASE)/src/samplers
	test -d $(OBJDIR_RELEASE)/src/tracers || mkdir -p $(OBJDIR_RELEASE)/src/tracers
	test -d $(OBJDIR_RELEASE)/src/objects || mkdir -p $(OBJDIR_RELEASE)/src/objects
	test -d $(OBJDIR_RELEASE)/src/glm/detail || mkdir -p $(OBJDIR_RELEASE)/src/glm/detail
	test -d $(OBJDIR_RELEASE)/src/brdfs || mkdir -p $(OBJDIR_RELEASE)/src/brdfs
	test -d $(OBJDIR_RELEASE)/src/backgrounds || mkdir -p $(OBJDIR_RELEASE)/src/backgrounds
	test -d $(OBJDIR_RELEASE)/src/cameras || mkdir -p $(OBJDIR_RELEASE)/src/cameras
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/src/lights/arealight.o: src/lights/arealight.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/lights/arealight.cpp -o $(OBJDIR_RELEASE)/src/lights/arealight.o

$(OBJDIR_RELEASE)/src/lights/ambient_occluder.o: src/lights/ambient_occluder.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/lights/ambient_occluder.cpp -o $(OBJDIR_RELEASE)/src/lights/ambient_occluder.o

$(OBJDIR_RELEASE)/src/lights/ambient.o: src/lights/ambient.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/lights/ambient.cpp -o $(OBJDIR_RELEASE)/src/lights/ambient.o

$(OBJDIR_RELEASE)/src/light.o: src/light.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/light.cpp -o $(OBJDIR_RELEASE)/src/light.o

$(OBJDIR_RELEASE)/src/lights/directional.o: src/lights/directional.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/lights/directional.cpp -o $(OBJDIR_RELEASE)/src/lights/directional.o

$(OBJDIR_RELEASE)/src/materials/reflective.o: src/materials/reflective.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/materials/reflective.cpp -o $(OBJDIR_RELEASE)/src/materials/reflective.o

$(OBJDIR_RELEASE)/src/materials/phong.o: src/materials/phong.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/materials/phong.cpp -o $(OBJDIR_RELEASE)/src/materials/phong.o

$(OBJDIR_RELEASE)/src/materials/matte.o: src/materials/matte.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/materials/matte.cpp -o $(OBJDIR_RELEASE)/src/materials/matte.o

$(OBJDIR_RELEASE)/src/materials/glossy_reflector.o: src/materials/glossy_reflector.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/materials/glossy_reflector.cpp -o $(OBJDIR_RELEASE)/src/materials/glossy_reflector.o

$(OBJDIR_RELEASE)/src/materials/emissive.o: src/materials/emissive.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/materials/emissive.cpp -o $(OBJDIR_RELEASE)/src/materials/emissive.o

$(OBJDIR_RELEASE)/src/material.o: src/material.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/material.cpp -o $(OBJDIR_RELEASE)/src/material.o

$(OBJDIR_RELEASE)/src/lights/pointlight.o: src/lights/pointlight.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/lights/pointlight.cpp -o $(OBJDIR_RELEASE)/src/lights/pointlight.o

$(OBJDIR_RELEASE)/src/tinyxml/tinystr.o: src/tinyxml/tinystr.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/tinyxml/tinystr.cpp -o $(OBJDIR_RELEASE)/src/tinyxml/tinystr.o

$(OBJDIR_RELEASE)/src/texture.o: src/texture.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/texture.cpp -o $(OBJDIR_RELEASE)/src/texture.o

$(OBJDIR_RELEASE)/src/serializable.o: src/serializable.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/serializable.cpp -o $(OBJDIR_RELEASE)/src/serializable.o

$(OBJDIR_RELEASE)/src/scheduler.o: src/scheduler.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/scheduler.cpp -o $(OBJDIR_RELEASE)/src/scheduler.o

$(OBJDIR_RELEASE)/src/tinyxml/tinyxml.o: src/tinyxml/tinyxml.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/tinyxml/tinyxml.cpp -o $(OBJDIR_RELEASE)/src/tinyxml/tinyxml.o

$(OBJDIR_RELEASE)/src/scene_parser.o: src/scene_parser.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/scene_parser.cpp -o $(OBJDIR_RELEASE)/src/scene_parser.o

$(OBJDIR_RELEASE)/src/samplers/regular.o: src/samplers/regular.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/samplers/regular.cpp -o $(OBJDIR_RELEASE)/src/samplers/regular.o

$(OBJDIR_RELEASE)/src/samplers/multi_jittered.o: src/samplers/multi_jittered.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/samplers/multi_jittered.cpp -o $(OBJDIR_RELEASE)/src/samplers/multi_jittered.o

$(OBJDIR_RELEASE)/src/world.o: src/world.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/world.cpp -o $(OBJDIR_RELEASE)/src/world.o

$(OBJDIR_RELEASE)/src/viewplane.o: src/viewplane.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/viewplane.cpp -o $(OBJDIR_RELEASE)/src/viewplane.o

$(OBJDIR_RELEASE)/src/tracers/whitted.o: src/tracers/whitted.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/tracers/whitted.cpp -o $(OBJDIR_RELEASE)/src/tracers/whitted.o

$(OBJDIR_RELEASE)/src/tracers/tracer.o: src/tracers/tracer.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/tracers/tracer.cpp -o $(OBJDIR_RELEASE)/src/tracers/tracer.o

$(OBJDIR_RELEASE)/src/sampler.o: src/sampler.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/sampler.cpp -o $(OBJDIR_RELEASE)/src/sampler.o

$(OBJDIR_RELEASE)/src/tracers/raycast.o: src/tracers/raycast.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/tracers/raycast.cpp -o $(OBJDIR_RELEASE)/src/tracers/raycast.o

$(OBJDIR_RELEASE)/src/tracers/area_lighting.o: src/tracers/area_lighting.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/tracers/area_lighting.cpp -o $(OBJDIR_RELEASE)/src/tracers/area_lighting.o

$(OBJDIR_RELEASE)/src/tinyxml/tinyxmlparser.o: src/tinyxml/tinyxmlparser.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/tinyxml/tinyxmlparser.cpp -o $(OBJDIR_RELEASE)/src/tinyxml/tinyxmlparser.o

$(OBJDIR_RELEASE)/src/tinyxml/tinyxmlerror.o: src/tinyxml/tinyxmlerror.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/tinyxml/tinyxmlerror.cpp -o $(OBJDIR_RELEASE)/src/tinyxml/tinyxmlerror.o

$(OBJDIR_RELEASE)/src/objects/compound.o: src/objects/compound.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/objects/compound.cpp -o $(OBJDIR_RELEASE)/src/objects/compound.o

$(OBJDIR_RELEASE)/src/objects/instance.o: src/objects/instance.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/objects/instance.cpp -o $(OBJDIR_RELEASE)/src/objects/instance.o

$(OBJDIR_RELEASE)/src/objects/grid.o: src/objects/grid.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/objects/grid.cpp -o $(OBJDIR_RELEASE)/src/objects/grid.o

$(OBJDIR_RELEASE)/src/objects/flat_mesh_triangle.o: src/objects/flat_mesh_triangle.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/objects/flat_mesh_triangle.cpp -o $(OBJDIR_RELEASE)/src/objects/flat_mesh_triangle.o

$(OBJDIR_RELEASE)/src/objects/disk.o: src/objects/disk.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/objects/disk.cpp -o $(OBJDIR_RELEASE)/src/objects/disk.o

$(OBJDIR_RELEASE)/src/object.o: src/object.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/object.cpp -o $(OBJDIR_RELEASE)/src/object.o

$(OBJDIR_RELEASE)/src/mymath.o: src/mymath.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/mymath.cpp -o $(OBJDIR_RELEASE)/src/mymath.o

$(OBJDIR_RELEASE)/src/mesh_triangle.o: src/mesh_triangle.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/mesh_triangle.cpp -o $(OBJDIR_RELEASE)/src/mesh_triangle.o

$(OBJDIR_RELEASE)/src/objects/plane.o: src/objects/plane.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/objects/plane.cpp -o $(OBJDIR_RELEASE)/src/objects/plane.o

$(OBJDIR_RELEASE)/src/objects/smooth_mesh_triangle.o: src/objects/smooth_mesh_triangle.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/objects/smooth_mesh_triangle.cpp -o $(OBJDIR_RELEASE)/src/objects/smooth_mesh_triangle.o

$(OBJDIR_RELEASE)/src/objects/sphere.o: src/objects/sphere.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/objects/sphere.cpp -o $(OBJDIR_RELEASE)/src/objects/sphere.o

$(OBJDIR_RELEASE)/src/objects/triangle.o: src/objects/triangle.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/objects/triangle.cpp -o $(OBJDIR_RELEASE)/src/objects/triangle.o

$(OBJDIR_RELEASE)/src/objects/triangle_mesh.o: src/objects/triangle_mesh.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/objects/triangle_mesh.cpp -o $(OBJDIR_RELEASE)/src/objects/triangle_mesh.o

$(OBJDIR_RELEASE)/src/ply.o: src/ply.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/ply.c -o $(OBJDIR_RELEASE)/src/ply.o

$(OBJDIR_RELEASE)/src/glm/detail/glm.o: src/glm/detail/glm.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/glm/detail/glm.cpp -o $(OBJDIR_RELEASE)/src/glm/detail/glm.o

$(OBJDIR_RELEASE)/src/glm/detail/dummy.o: src/glm/detail/dummy.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/glm/detail/dummy.cpp -o $(OBJDIR_RELEASE)/src/glm/detail/dummy.o

$(OBJDIR_RELEASE)/src/bbox.o: src/bbox.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/bbox.cpp -o $(OBJDIR_RELEASE)/src/bbox.o

$(OBJDIR_RELEASE)/src/brdfs/perfect_specular.o: src/brdfs/perfect_specular.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/brdfs/perfect_specular.cpp -o $(OBJDIR_RELEASE)/src/brdfs/perfect_specular.o

$(OBJDIR_RELEASE)/src/brdfs/lambertian.o: src/brdfs/lambertian.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/brdfs/lambertian.cpp -o $(OBJDIR_RELEASE)/src/brdfs/lambertian.o

$(OBJDIR_RELEASE)/src/brdfs/glossy_specular.o: src/brdfs/glossy_specular.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/brdfs/glossy_specular.cpp -o $(OBJDIR_RELEASE)/src/brdfs/glossy_specular.o

$(OBJDIR_RELEASE)/src/backgrounds/sphere_sky.o: src/backgrounds/sphere_sky.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/backgrounds/sphere_sky.cpp -o $(OBJDIR_RELEASE)/src/backgrounds/sphere_sky.o

$(OBJDIR_RELEASE)/src/backgrounds/single_color.o: src/backgrounds/single_color.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/backgrounds/single_color.cpp -o $(OBJDIR_RELEASE)/src/backgrounds/single_color.o

$(OBJDIR_RELEASE)/src/background.o: src/background.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/background.cpp -o $(OBJDIR_RELEASE)/src/background.o

$(OBJDIR_RELEASE)/src/camera.o: src/camera.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/camera.cpp -o $(OBJDIR_RELEASE)/src/camera.o

$(OBJDIR_RELEASE)/src/cameras/pinhole.o: src/cameras/pinhole.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/cameras/pinhole.cpp -o $(OBJDIR_RELEASE)/src/cameras/pinhole.o

$(OBJDIR_RELEASE)/src/cameras/thinlens.o: src/cameras/thinlens.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/cameras/thinlens.cpp -o $(OBJDIR_RELEASE)/src/cameras/thinlens.o

$(OBJDIR_RELEASE)/src/datastore.o: src/datastore.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src/datastore.cpp -o $(OBJDIR_RELEASE)/src/datastore.o

$(OBJDIR_RELEASE)/main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)/main.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)/src/lights
	rm -rf $(OBJDIR_RELEASE)/src
	rm -rf $(OBJDIR_RELEASE)/src/materials
	rm -rf $(OBJDIR_RELEASE)/src/tinyxml
	rm -rf $(OBJDIR_RELEASE)/src/samplers
	rm -rf $(OBJDIR_RELEASE)/src/tracers
	rm -rf $(OBJDIR_RELEASE)/src/objects
	rm -rf $(OBJDIR_RELEASE)/src/glm/detail
	rm -rf $(OBJDIR_RELEASE)/src/brdfs
	rm -rf $(OBJDIR_RELEASE)/src/backgrounds
	rm -rf $(OBJDIR_RELEASE)/src/cameras
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

