﻿# CMakeList.txt : projet CMake pour Raytracer, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("Raytracer")

if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
endif()

# Current directory is Synthese_TP1
set(glm_DIR ../libraries/glm-master/cmake/glm)
find_package( glm REQUIRED )

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ../libraries/SFML/lib/cmake/SFML)
find_package(SFML 2.5.1 COMPONENTS graphics window REQUIRED)

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Raytracer "Raytracer.cpp" "Raytracer.h"  "Ray.h"  "SceneObject.h" "Sphere.h"   "Light.h" "Scene.h" "Scene.cpp" "Camera.h" "Sphere.cpp" "OrthographicCamera.h" "PerspectiveCamera.h" "AABB.h" "AABB.cpp" "BVHNode.h" "BVHNode.cpp")

target_link_libraries(${PROJECT_NAME} glm::glm)
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window)
