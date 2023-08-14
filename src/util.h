//
// Created by Thibeau on 8/14/2023.
//

#ifndef KOREANWORDLIST_UTIL_H
#define KOREANWORDLIST_UTIL_H

#include <string>
#include "Date.h"

int countLeapYears(Date d);
int getDifference(Date dt1, Date dt2);
Date get_date_from_wstring(std::wstring date_string);

#endif //KOREANWORDLIST_UTIL_H
