project('raylibtest', 'cpp', default_options: ['cpp_std=c++17'])
sources = ['main.cpp', 'Game.cpp', 'LibLoader.cpp']

include_dirs = include_directories('./interface', './include')

#'-fno-omit-frame-pointer' '-fsanitize=address'

raylib_dep = [dependency('raylib')]
#debug_deps =  dependency('')
build_flags = ['-g']
linking_flags = []

subdir('modules')

executable('raylibtest.app',
           sources: sources,
           dependencies: raylib_dep,
           include_directories: include_dirs,
           cpp_args: build_flags,
           link_args: linking_flags)