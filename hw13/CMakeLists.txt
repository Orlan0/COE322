cmake_minimum_required( VERSION 3.12 )
project( hw13 VERSION 1.0 )

add_executable( hw13 hw13.cpp )
target_compile_features( hw13 PRIVATE cxx_std_20 )

find_package( Eigen3 REQUIRED  )
target_link_libraries( hw13 PUBLIC Eigen3::Eigen )

install( TARGETS hw13 DESTINATION . )

# emacs:
## ESC x repl<sp>st<sp>
# vi:
## 1,$s/oldstring/newstring/g
