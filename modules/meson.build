

test_shared_sources= ['test.cpp']
build_flags_test_lib = ['-g', '-fPIC']

link_args_test_lib = ['-fPIC']

test_lib = shared_library(
    'test_shared',
    sources: test_shared_sources,
    include_directories: include_dirs,
    dependencies: raylib_dep,
    cpp_args: build_flags_test_lib,
    link_args: link_args_test_lib
    )