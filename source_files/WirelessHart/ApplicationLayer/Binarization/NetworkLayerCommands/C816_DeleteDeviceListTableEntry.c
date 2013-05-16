/*
* Copyright (C) 2013 Nivis LLC.
* Email:   opensource@nivis.com
* Website: http://www.nivis.com
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 3 of the License.
* 
* Redistribution and use in source and binary forms must retain this
* copyright notice.

* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*/

#include "C816_DeleteDeviceListTableEntry.h"

uint8_t Compose_C816_DeleteDeviceListTableEntry_Req ( C816_DeleteDeviceListTableEntry_Req* request,
                                    BinaryStream* toStream )
{
  STREAM_WRITE_UINT8(toStream, request->m_ucDeviceListCode);
  STREAM_WRITE_BYTES(toStream, request->m_aDeviceUniqueId, 5);

  return RCS_N00_Success; // success
}

uint8_t Parse_C816_DeleteDeviceListTableEntry_Req ( C816_DeleteDeviceListTableEntry_Req* request,
                                    BinaryStream* fromStream )
{
#if defined(_DEBUG)
  if (STREAM_GetRemainingSize(fromStream) > C816_ReqSize)
    return RCS_E01_Undefined1; // too many bytes
#endif

  STREAM_READ_UINT8(fromStream, &request->m_ucDeviceListCode);
  STREAM_READ_BYTES(fromStream, &request->m_aDeviceUniqueId, 5);

  return RCS_N00_Success; // success
}

uint8_t Compose_C816_DeleteDeviceListTableEntry_Resp ( C816_DeleteDeviceListTableEntry_Resp* response,
                                    BinaryStream* toStream )
{
  STREAM_WRITE_UINT8(toStream, response->m_ucDeviceListCode);
  STREAM_WRITE_BYTES(toStream, response->m_aDeviceUniqueId, 5);
  STREAM_WRITE_UINT16(toStream, response->m_unNoOfListEntriesRemaining);

  return RCS_N00_Success; // success
}

uint8_t Parse_C816_DeleteDeviceListTableEntry_Resp ( C816_DeleteDeviceListTableEntry_Resp* response,
                                    BinaryStream* fromStream )
{
#if defined(_DEBUG)
  if (STREAM_GetRemainingSize(fromStream) > C816_RespSize)
    return RCS_E01_Undefined1; // too many bytes
#endif

  STREAM_READ_UINT8(fromStream, &response->m_ucDeviceListCode);
  STREAM_READ_BYTES(fromStream, &response->m_aDeviceUniqueId, 5);
  STREAM_READ_UINT16(fromStream, &response->m_unNoOfListEntriesRemaining);

  return RCS_N00_Success; // success
}
