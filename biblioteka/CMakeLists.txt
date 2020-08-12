cmake_minimum_required(VERSION 3.5)
project(Biblioteka)

set(SOURCE_FILES
        src/model/Address.cpp
        src/model/AddressException.cpp
        src/model/Bicycle.cpp
        src/model/Car.cpp
        src/model/Client.cpp
        src/model/ClientException.cpp
        src/model/ClientRepository.cpp
        src/model/ClientType.cpp
        src/model/ClientTypePremium.cpp
        src/model/ClientTypeRegular.cpp
        src/model/ClientTypeVip.cpp
        src/model/Moped.cpp
        src/model/MotorVehicle.cpp
        src/model/Rent.cpp
        src/model/RentException.cpp
        src/model/RentsManager.cpp
        src/model/RentsRepository.cpp
        src/model/RentsRepositoryException.cpp
        src/model/Vehicle.cpp
        src/model/VehicleException.cpp
        src/model/VehicleRepository.cpp
        src/model/VehicleRepositoryException.cpp
        src/model/ClientManager.cpp
        src/model/VehicleManager.cpp
        src/model/ClientManagerException.cpp
        src/model/VehicleManagerException.cpp
        src/model/ClientRepositoryException.cpp
        )

add_library(Biblioteka ${SOURCE_FILES})

target_include_directories(Biblioteka PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/model)

#Konfiguracja testów jednostkowych:
enable_testing()

find_package (Boost 1.60.0 COMPONENTS "date_time" REQUIRED)
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)


set(SOURCE_ALL_TEST_FILES
        test/master.cpp
        test/RentTest.cpp
        test/ClientRepositoryTest.cpp
        test/ClientTest.cpp
        test/VehiclesTest.cpp
        test/RentsManagerTest.cpp
        test/RentsRepositoryTest.cpp
        test/AddressTest.cpp
        test/VehicleRepositoryTest.cpp
        test/ClientManagerTest.cpp
        test/VehicleManagerTest.cpp
        )
set(SOURCE_RENT_TEST_FILES
        test/master.cpp
        test/RentTest.cpp
        )
set(SOURCE_CLIENT_REPOSITORY_TEST_FILES
        test/master.cpp
        test/ClientRepositoryTest.cpp
        )
set(SOURCE_CLIENT_TEST_FILES
        test/master.cpp
        test/ClientTest.cpp
        )
set(SOURCE_VEHICLES_TEST_FILES
        test/master.cpp
        test/VehiclesTest.cpp
        )
set(SOURCE_RENTS_MANAGER_TEST_FILES
        test/master.cpp
        test/RentsManagerTest.cpp
        )
set(SOURCE_RENTS_REPOSITORY_TEST_FILES
        test/master.cpp
        test/RentsRepositoryTest.cpp
        )
set(SOURCE_ADDRESS_TEST_FILES
        test/master.cpp
        test/AddressTest.cpp
        )
set(SOURCE_VEHICLE_REPOSITORY_TEST_FILES
        test/master.cpp
        test/VehicleRepositoryTest.cpp
        )
set(SOURCE_CLIENT_MANAGER_TEST_FILES
        test/master.cpp
        test/ClientManagerTest.cpp
        )
set(SOURCE_VEHICLE_MANAGER_TEST_FILES
        test/master.cpp
        test/VehicleManagerTest.cpp
        )

add_executable (AllTests ${SOURCE_ALL_TEST_FILES})
add_executable (RentTest ${SOURCE_RENT_TEST_FILES})
add_executable (ClientRepositoryTest ${SOURCE_CLIENT_REPOSITORY_TEST_FILES})
add_executable (ClientTest ${SOURCE_CLIENT_TEST_FILES})
add_executable (VehiclesTest ${SOURCE_VEHICLES_TEST_FILES})
add_executable (RentsManagerTest ${SOURCE_RENTS_MANAGER_TEST_FILES})
add_executable (RentsRepositoryTest ${SOURCE_RENTS_REPOSITORY_TEST_FILES})
add_executable (AddressTest ${SOURCE_ADDRESS_TEST_FILES})
add_executable (VehicleRepositoryTest ${SOURCE_VEHICLE_REPOSITORY_TEST_FILES})
add_executable (ClientManagerTest ${SOURCE_CLIENT_MANAGER_TEST_FILES})
add_executable (VehicleManagerTest ${SOURCE_VEHICLE_MANAGER_TEST_FILES})


#dołącz bibliotekę z testowanymi klasami do programu testów
target_link_libraries (AllTests
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (RentTest
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (ClientRepositoryTest
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (ClientTest
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (VehiclesTest
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (RentsManagerTest
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (RentsRepositoryTest
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (AddressTest
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (VehicleRepositoryTest
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (ClientManagerTest
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (VehicleManagerTest
        Biblioteka
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test RentTest. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.

add_test(TestBiblioteki AllTests
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestBiblioteki RentTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestBiblioteki ClientRepositoryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestBiblioteki ClientTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestBiblioteki VehiclesTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestBiblioteki RentsManagerTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestBiblioteki RentsRepositoryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestBiblioteki AddressTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestBiblioteki VehicleRepositoryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestBiblioteki ClientManagerTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(TestBiblioteki VehicleManagerTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

#Aby raport testów był szczegółowo wypisany na konsolę:
add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
      ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
       WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

#Konfiguracja szczegółowości logowania odbywa się z poziomu konfiguracji zmiennych środowiskowych BOOST_TEST_XXXX.
#W tym przypadku ustawiony jest odpowiednik --log_level

