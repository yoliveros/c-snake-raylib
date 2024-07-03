project('snake', 'c', default_options : ['c_std=c17'])

compiler = meson.get_compiler('c')

include = include_directories(
  'src'
)

deps = [
  compiler.find_library('raylib', 
    dirs: [meson.current_source_dir() + '/src/lib']
  )
]

src = ['src/main.c', 'src/SnakeBody.c']

executable('snake', 
  src,
  include_directories : include, 
  dependencies: deps
)
