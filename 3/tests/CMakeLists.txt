cmake_minimum_required(VERSION 3.16)

find_package(Catch2 2 REQUIRED)

# Object
add_executable(object_testing object_testing.cpp)
target_link_libraries(object_testing objects Catch2::Catch2)

# Artifact
add_executable(artifact_testing artifact_testing.cpp)
target_link_libraries(artifact_testing objects Catch2::Catch2)

# Enchanted
add_executable(enchanted_testing enchanted_testing.cpp)
target_link_libraries(enchanted_testing objects Catch2::Catch2)

# Equipment
add_executable(equipment_testing equipment_testing.cpp)
target_link_libraries(equipment_testing objects Catch2::Catch2)

# ArtifactEquipment
add_executable(artifact_equipment_testing artifact_equipment_testing.cpp)
target_link_libraries(artifact_equipment_testing objects Catch2::Catch2)

# Weapon
add_executable(weapon_testing weapon_testing.cpp)
target_link_libraries(weapon_testing objects Catch2::Catch2)

# ArtifactWeapon
add_executable(artifact_weapon_testing artifact_weapon_testing.cpp)
target_link_libraries(artifact_weapon_testing objects Catch2::Catch2)

# EnchantedWeapon
add_executable(enchanted_weapon_testing enchanted_weapon_testing.cpp)
target_link_libraries(enchanted_weapon_testing objects Catch2::Catch2)

# MixedWeapon
add_executable(mixed_weapon_testing mixed_weapon_testing.cpp)
target_link_libraries(mixed_weapon_testing objects Catch2::Catch2)

# Potion
add_executable(potion_testing potion_testing.cpp)
target_link_libraries(potion_testing objects Catch2::Catch2)