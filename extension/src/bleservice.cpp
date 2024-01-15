#include "bleservice.h"


BLEService::BLEService() {
    // Clean up your service and characteristic here
}

BLEService::BLEService(SimpleBLE::BluetoothUUID serviceUUID, SimpleBLE::BluetoothUUID characteristicUUID) {
    uuids_ = std::make_pair(serviceUUID, characteristicUUID);
}


BLEService::BLEService(SimpleBLE::Service* service, SimpleBLE::Characteristic* characteristic){
  characteristic_ = characteristic;
  service_ = service;

}

BLEService::~BLEService() {
    // Clean up your service and characteristic here
}

std::pair<SimpleBLE::BluetoothUUID, SimpleBLE::BluetoothUUID> BLEService::getUUIDs() {
    return uuids_;
}

Array BLEService::getUUIDsInArray() {
    Array uuids = Array();
    return uuids;
}

bool BLEService::can_notify() {
    return characteristic_->can_notify();
}

bool BLEService::can_read() {
    return characteristic_->can_read();
}

void BLEService::_bind_methods() {
  ClassDB::bind_method(D_METHOD("getUUIDsInArray"), &BLEService::getUUIDsInArray);
  ClassDB::bind_method(D_METHOD("can_notiy"), &BLEService::can_notify);
  ClassDB::bind_method(D_METHOD("can_read"), &BLEService::can_read);
}
