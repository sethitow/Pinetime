#pragma once

#include <cstdint>
#include "AlertNotificationClient.h"
#include "DeviceInformationService.h"
#include "CurrentTimeClient.h"
#include <host/ble_gap.h>

namespace Pinetime {
  namespace Controllers {
    class DateTime;
    class NimbleController {
      public:
        NimbleController(Pinetime::System::SystemTask& systemTask, DateTime& dateTimeController, Pinetime::Controllers::NotificationManager& notificationManager);
        void Init();
        void StartAdvertising();
        int OnGAPEvent(ble_gap_event *event);

        int OnDiscoveryEvent(uint16_t i, const ble_gatt_error *pError, const ble_gatt_svc *pSvc);
      private:
        static constexpr char* deviceName = "Pinetime-JF";
        Pinetime::System::SystemTask& systemTask;
        DateTime& dateTimeController;
        Pinetime::Controllers::NotificationManager& notificationManager;

        DeviceInformationService deviceInformationService;
        CurrentTimeClient currentTimeClient;
        AlertNotificationClient alertNotificationClient;
        uint8_t addrType;
        uint16_t connectionHandle;
    };
  }
}