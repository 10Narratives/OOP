//
// Created by vanish2 on 23.12.23.
//

#include <iostream>
#include <vector>
#include "entities/placeables/include/Enemy.h"
#include <thread>
#include <chrono>
#include <fstream>

std::vector<Enemy> make_enemies(int number_of_enemies) {
    auto data = R"({
            "x": 1,
            "y": 1,
            "primary": {
              "power": 10,
              "ability": 15,
              "endurance": 5,
              "health_limit": 100,
              "health": 70
            },
            "exp": 30
        })"_json;
    std::vector<Enemy> enemies;
    for(int i = 0; i < number_of_enemies; i++) {
        Enemy new_enemy;
        new_enemy.be_loaded(data);
        enemies.push_back(new_enemy);
    }
    return enemies;
}

void update(const Enemy& before) {
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
}

void mono() {
    std::ofstream mono("mono.txt");
    for(int i = 0;  i < 100; i++) {
        auto enemies = make_enemies(i);
        auto start = std::chrono::high_resolution_clock::now();
        for(const auto& enemy : enemies) {
            update(enemy);
        }
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        mono << duration.count() << std::endl;
    }
    mono.close();
}

void update_thread(std::vector<Enemy>::iterator first,
                   std::vector<Enemy>::iterator last, std::vector<Enemy>::iterator first_out) {
    for(;first != last; ++first) {
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
        *first_out = *first;
        ++first_out;
    }
}

void multi() {
    std::ofstream multi("multi.txt");
    for (int i = 0; i < 100; ++i) {
        auto enemies = make_enemies(i);
        std::vector<Enemy> after_update(enemies.size());
        auto thread_number = std::thread::hardware_concurrency();
        std::vector<std::thread> threads(thread_number);
        auto elements = std::distance(enemies.begin(), enemies.end());
        auto start_time = std::chrono::high_resolution_clock::now();
        for (size_t k = 0; k < thread_number; ++k) {
            size_t start_k = k * elements / thread_number;
            size_t end_k = (k + 1) * elements /  thread_number;
            auto start = std::next(enemies.begin(), start_k);
            auto end = std::next(enemies.begin(), end_k);
            auto res_start = std::next(after_update.begin(), start_k);
            threads[k] = std::thread(
                    [=](){ update_thread(start, end, res_start);}
                    );
        }
        for(auto& th : threads) {
            th.join();
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end_time - start_time;
        multi << duration.count() << std::endl;
    }
    multi.close();
}

int main() {
    try{
        mono();
        multi();
    } catch(const std::bad_alloc& ba) {
        std::cout << "Not enough memory." << std::endl;
        return 1;
    }
    return 0;
}