project('raylibtest', 'cpp', default_options: ['cpp_std=c++17'])
sources = ['main.cpp', 'Game.cpp', 'LibLoader.cpp']

include_dirs = include_directories('./interface', './include')

#'-fno-omit-frame-pointer' 

raylib_dep = [dependency('raylib')]
#debug_deps =  dependency('')
build_flags = ['-g', '-fsanitize=address']
linking_flags = ['-fsanitize=address']

# subdir('modules')

executable('raylibtest.app',
           sources: sources,
           dependencies: raylib_dep,
           include_directories: include_dirs,
           cpp_args: build_flags,
           link_args: linking_flags)