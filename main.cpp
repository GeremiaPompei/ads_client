#include <iostream>

#include "AdsLib/AdsLib.h"
#include "AdsLib/AdsVariable.h"

using namespace std;

static void readAndWrite(std::ostream& out, const AdsDevice& route)
{
    AdsVariable<uint8_t> var1 {route, 0x0000, 0};
    AdsVariable<uint8_t> var2 {route, 0x0004, 0};
    AdsVariable<uint8_t> var3 {route, 0x0008, 0};
    AdsVariable<uint8_t> var4 {route, 0x000B, 0};
    AdsVariable<uint8_t> var5 {route, 0x000D, 0};
    AdsVariable<uint8_t> var6 {route, 0x000F, 3};

    out << "Read:\n";
    out << "ADS read " << hex << (uint32_t)var1 << '\n';
    out << "ADS read " << hex << (uint32_t)var2 << '\n';
    out << "ADS read " << hex << (uint32_t)var3 << '\n';
    out << "ADS read " << hex << (uint16_t)var4 << '\n';
    out << "ADS read " << hex << (uint16_t)var5 << '\n';
    out << "ADS read " << hex << (bool)var6 << '\n';
    
    var1 = (uint32_t)1;
    var2 = (uint32_t)2;
    var3 = (uint32_t)3;
    var4 = (uint16_t)4;
    var5 = (uint16_t)5;
    var6 = true;
    
    out << "Write:\n";
    out << "ADS write " << hex << (uint32_t)var1 << '\n';
    out << "ADS write " << hex << (uint32_t)var2 << '\n';
    out << "ADS write " << hex << (uint32_t)var3 << '\n';
    out << "ADS read " << hex << (uint16_t)var4 << '\n';
    out << "ADS write " << hex << (uint16_t)var5 << '\n';
    out << "ADS write " << hex << (bool)var6 << '\n';
}

static void configAndRun(ostream& out)
{
    static const AmsNetId remoteNetId { 192, 168, 0, 231, 1, 1 };
    static const char remoteIpV4[] = "ads-server";

    // uncomment and adjust if automatic AmsNetId deduction is not working as expected
    //AdsSetLocalAddress({192, 168, 0, 1, 1, 1});

    AdsDevice route {remoteIpV4, remoteNetId, AMSPORT_R0_PLC_TC3};
    readAndWrite(out, route);
}

int main()
{
    try {
        configAndRun(cout);
    } catch (const AdsException& ex) {
        cout << "Error: " << ex.errorCode << "\n";
        cout << "AdsException message: " << ex.what() << "\n";
    } catch (const runtime_error& ex) {
        cout << ex.what() << '\n';
    }
    cout << "Hit ENTER to Exit.\n";
    cin.ignore();
}
