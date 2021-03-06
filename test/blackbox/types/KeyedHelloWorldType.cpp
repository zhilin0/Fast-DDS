// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*!
 * @file deadlinepayloadPubSubTypes.cpp
 * This header file contains the implementation of the serialization functions.
 *
 * This file was generated by the tool fastcdrgen.
 */


#include <fastcdr/FastBuffer.h>
#include <fastcdr/Cdr.h>

#include "KeyedHelloWorldType.h"

using namespace eprosima::fastrtps;
using namespace eprosima::fastrtps::rtps;

KeyedHelloWorldType::KeyedHelloWorldType()
{
    setName("KeyedHelloWorld");
    m_typeSize = (uint32_t)KeyedHelloWorld::getMaxCdrSerializedSize() + 4 /*encapsulation*/;
    m_isGetKeyDefined = KeyedHelloWorld::isKeyDefined();
    m_keyBuffer = (unsigned char*)calloc(
        KeyedHelloWorld::getKeyMaxCdrSerializedSize() > 16 ? KeyedHelloWorld::getKeyMaxCdrSerializedSize() : 16,
        sizeof(unsigned char*));
}

KeyedHelloWorldType::~KeyedHelloWorldType()
{
    if (m_keyBuffer != nullptr)
    {
        free(m_keyBuffer);
    }
}

bool KeyedHelloWorldType::serialize(
        void* data,
        SerializedPayload_t* payload)
{
    KeyedHelloWorld* p_type = (KeyedHelloWorld*) data;
    eprosima::fastcdr::FastBuffer fastbuffer((char*) payload->data, payload->max_size); // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR);
    payload->encapsulation = ser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;
    // Serialize encapsulation
    ser.serialize_encapsulation();

    try
    {
        p_type->serialize(ser); // Serialize the object:
    }
    catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    payload->length = (uint32_t)ser.getSerializedDataLength();  //Get the serialized length
    return true;
}

bool KeyedHelloWorldType::deserialize(
        SerializedPayload_t* payload,
        void* data)
{
    KeyedHelloWorld* p_type = (KeyedHelloWorld*) data;  //Convert DATA to pointer of your type
    eprosima::fastcdr::FastBuffer fastbuffer((char*)payload->data, payload->length);    // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr deser(fastbuffer, eprosima::fastcdr::Cdr::DEFAULT_ENDIAN,
            eprosima::fastcdr::Cdr::DDS_CDR); // Object that deserializes the data.
    // Deserialize encapsulation.
    deser.read_encapsulation();
    payload->encapsulation = deser.endianness() == eprosima::fastcdr::Cdr::BIG_ENDIANNESS ? CDR_BE : CDR_LE;

    try
    {
        p_type->deserialize(deser); //Deserialize the object:
    }
    catch (eprosima::fastcdr::exception::NotEnoughMemoryException& /*exception*/)
    {
        return false;
    }

    return true;
}

std::function<uint32_t()> KeyedHelloWorldType::getSerializedSizeProvider(
        void* data)
{
    return [data]() -> uint32_t
           {
               return (uint32_t)type::getCdrSerializedSize(*static_cast<KeyedHelloWorld*>(data)) + 4 /*encapsulation*/;
           };
}

void* KeyedHelloWorldType::createData()
{
    return (void*)new KeyedHelloWorld();
}

void KeyedHelloWorldType::deleteData(
        void* data)
{
    delete((KeyedHelloWorld*)data);
}

bool KeyedHelloWorldType::getKey(
        void* data,
        InstanceHandle_t* handle,
        bool force_md5)
{
    if (!m_isGetKeyDefined)
    {
        return false;
    }
    KeyedHelloWorld* p_type = (KeyedHelloWorld*) data;
    eprosima::fastcdr::FastBuffer fastbuffer((char*)m_keyBuffer, KeyedHelloWorld::getKeyMaxCdrSerializedSize());     // Object that manages the raw buffer.
    eprosima::fastcdr::Cdr ser(fastbuffer, eprosima::fastcdr::Cdr::BIG_ENDIANNESS);     // Object that serializes the data.
    p_type->serializeKey(ser);
    if (force_md5 || KeyedHelloWorld::getKeyMaxCdrSerializedSize() > 16)
    {
        m_md5.init();
        m_md5.update(m_keyBuffer, (unsigned int)ser.getSerializedDataLength());
        m_md5.finalize();
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_md5.digest[i];
        }
    }
    else
    {
        for (uint8_t i = 0; i < 16; ++i)
        {
            handle->value[i] = m_keyBuffer[i];
        }
    }
    return true;
}

bool KeyedHelloWorldType::is_bounded() const
{
    return true;
}

bool KeyedHelloWorldType::is_plain() const
{
    return false;
}
