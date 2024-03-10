project('raylibtest', 'cpp')
sources = ['main.cpp']

raylib_dep = dependency('raylib')
#debug_deps =  dependency('')
build_flags = ['-fsanitize=address', '-fno-omit-frame-pointer', '-g']
linking_flags = ['-fsanitize=address', '-fno-omit-frame-pointer']

executable('raylibtest.app',
           sources: sources,
           dependencies: raylib_dep,
           cpp_args: build_flags,
           link_args: linking_flags)