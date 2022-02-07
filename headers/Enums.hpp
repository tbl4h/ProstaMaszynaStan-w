#pragma once
#include <iostream>
#include <fstream>
using namespace std;
enum class MainState {
    ListMenu,
    Create,
    Write,
    Read,
    Exit,
};
enum class MainTrigger {
    ToMenu,
    ToCreate,
    ToWrite,
    ToRead,
    ToExit
};