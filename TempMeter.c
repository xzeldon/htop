#include "TempMeter.h"

#include "CRT.h"
#include "Object.h"
#include "Platform.h"
#include "XUtils.h"

static const int TempMeter_attributes[] = {
    TEMP};

static void TempMeter_updateValues(Meter *this)
{
   float temp_c = Platform_getTemp();

   xSnprintf(this->txtBuffer, sizeof(this->txtBuffer), "%.1lf °C", temp_c);
}

const MeterClass TempMeter_class = {
    .super = {
        .extends = Class(Meter),
        .delete = Meter_delete},
    .updateValues = TempMeter_updateValues,
    .defaultMode = TEXT_METERMODE,
    .maxItems = 1,
    .total = 100.0,
    .attributes = TempMeter_attributes,
    .name = "Temp",
    .uiName = "Temp",
    .caption = "CPU/Temperature: "};
