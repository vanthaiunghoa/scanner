set(SOURCE_FILES
  info_from_frame_kernel.cpp
  discard_kernel.cpp
  sleep_kernel.cpp
  test_increment_kernel.cpp
  packed_file_source.cpp
  pass_kernel.cpp
  python_source.cpp
  files_source.cpp
  files_sink.cpp
  sql_source.cpp
  sql_sink.cpp
  sql.cpp
  audio_source.cpp)

add_library(misc OBJECT ${SOURCE_FILES})
