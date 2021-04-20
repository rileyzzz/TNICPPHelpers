#pragma once
#include "trainznativeinterface.hpp"
#include "TNIStream.hpp"
#include "TNIFunctions.hpp"
#include "TNILibrary.hpp"
#include "TNILabel.hpp"
#include "TNIBuffer.h"
#include "TNIPhysics.hpp"
#include <vector>
#include <typeinfo>

#ifndef _TNICPPHELPERS_H_
#define _TNICPPHELPERS_H_

//=============================================================================
// TNIStream read operators
//=============================================================================


inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, const TNIAssetID* data)
{
    TNIStreamWriteAssetID(stream, data);
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, const TNIString* data)
{
    TNIStreamWriteString(stream, data);
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, const TNIObject* data)
{
    TNIStreamWriteTNIObjectReference(stream, data);
    return stream;
}

//inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, const TNIRef<const TNIObject>& data)
//{
//    uint32_t objclass = TNIGetObjectClass(data.c_obj());
//    if  (objclass == TNI_CLASS_ASSETID)     TNIStreamWriteAssetID(stream, data);
//    else if (objclass == TNI_CLASS_STRING)  TNIStreamWriteString(stream, data);
//    else                                    TNIStreamWriteTNIObjectReference(stream, data);
//
//    return stream;
//}


inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, const float& data)
{
    TNIStreamWriteFloat(stream, data);
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, std::vector<float> data)
{
    TNIStreamWriteFloatArray(stream, data.data(), (int)data.size());
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, const double& data)
{
    TNIStreamWriteFloat64(stream, data);
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, std::vector<double> data)
{
    TNIStreamWriteFloat64Array(stream, data.data(), (int)data.size());
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, const int8_t& data)
{
    TNIStreamWriteInt8(stream, data);
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, std::vector<int8_t> data)
{
    TNIStreamWriteInt8Array(stream, data.data(), (int)data.size());
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, const int16_t& data)
{
    TNIStreamWriteInt16(stream, data);
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, std::vector<int16_t> data)
{
    TNIStreamWriteInt16Array(stream, data.data(), (int)data.size());
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, const int32_t& data)
{
    TNIStreamWriteInt32(stream, data);
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, std::vector<int32_t> data)
{
    TNIStreamWriteInt32Array(stream, data.data(), (int)data.size());
    return stream;
}

inline TNIRef<TNIStream>& operator<<(TNIRef<TNIStream>& stream, const int64_t& data)
{
    TNIStreamWriteInt64(stream, data);
    return stream;
}


//=============================================================================
// TNIStream write operators
//=============================================================================

//inline TNIRef<TNIStream>& operator>>(TNIRef<TNIStream>& stream, TNIAssetID* data)
//{
//    data = TNIStreamReadAssetID(stream).c_obj_inc();
//    return stream;
//}
//
//inline TNIRef<TNIStream>& operator>>(TNIRef<TNIStream>& stream, TNIString* data)
//{
//    data = TNIStreamReadString(stream).c_obj_inc();
//    return stream;
//}
//
//inline TNIRef<TNIStream>& operator>>(TNIRef<TNIStream>& stream, TNIObject* data)
//{
//    data = TNIStreamReadTNIObjectReference(stream).c_obj_inc();
//    return stream;
//}

inline const TNIRef<TNIStream>& operator>>(const TNIRef<TNIStream>& stream, TNIRef<const TNIObject>& data)
{
    data = TNIStreamReadTNIObjectReference(stream);
    return stream;
}

inline const TNIRef<TNIStream>& operator>>(const TNIRef<TNIStream>& stream, float& data)
{ 
    data = TNIStreamReadFloat(stream);
    return stream;
}

//inline TNIRef<TNIStream>& operator>>(TNIRef<TNIStream>& stream, std::vector<float>& data)
//{
//    TNIStreamWriteFloatArray(stream, data.data(), data.size());
//    return stream;
//}

inline const TNIRef<TNIStream>& operator>>(const TNIRef<TNIStream>& stream, double& data)
{
    data = TNIStreamReadFloat64(stream);
    return stream;
}

//inline TNIRef<TNIStream>& operator>>(TNIRef<TNIStream>& stream, std::vector<double> data)
//{
//    TNIStreamWriteFloat64Array(stream, data.data(), data.size());
//    return stream;
//}

inline const TNIRef<TNIStream>& operator>>(const TNIRef<TNIStream>& stream, int8_t& data)
{
    data = TNIStreamReadInt8(stream);
    return stream;
}

//inline TNIRef<TNIStream>& operator>>(TNIRef<TNIStream>& stream, std::vector<int8_t> data)
//{
//    TNIStreamWriteInt8Array(stream, data.data(), data.size());
//    return stream;
//}

inline const TNIRef<TNIStream>& operator>>(const TNIRef<TNIStream>& stream, int16_t& data)
{
    data = TNIStreamReadInt16(stream);
    return stream;
}

//inline TNIRef<TNIStream>& operator>>(TNIRef<TNIStream>& stream, std::vector<int16_t> data)
//{
//    TNIStreamWriteInt16Array(stream, data.data(), data.size());
//    return stream;
//}

inline const TNIRef<TNIStream>& operator>>(const TNIRef<TNIStream>& stream, int32_t& data)
{
    data = TNIStreamReadInt32(stream);
    return stream;
}

//inline TNIRef<TNIStream>& operator>>(TNIRef<TNIStream>& stream, std::vector<int32_t> data)
//{
//    TNIStreamWriteInt32Array(stream, data.data(), data.size());
//    return stream;
//}

inline const TNIRef<TNIStream>& operator>>(const TNIRef<TNIStream>& stream, int64_t& data)
{
    data = TNIStreamReadInt64(stream);
    return stream;
}

//
//inline TNIRef<TNIStream> operator>>(TNIRef<TNIStream>& stream, std::vector<int64_t> data)
//{
//    TNIStreamWriteInt64Array(stream, data.data(), data.size());
//    return stream;
//}


//template <class T>
//inline TNIRef<T> TNICast(TNIRefParam<TNIObject> object);

//explicit instantiation
//template TNIRef<TNIStream> TNICast<TNIStream>(TNIRefParam<TNIObject> object);

//=============================================================================
// Casting templates
//=============================================================================

//template <class T>
//inline TNIRef<T> TNICast(TNIRefParam<TNIObject> object)
//{
//    TNI_ASSERT(false);
//    return object;
//}
//template <>
//inline TNIRef<TNIStream> TNICast<TNIStream>(TNIRefParam<TNIObject> object)
//{
//    return TNICastStream(object);
//}

template<class T>
constexpr uint32_t TNI_typeid()
{
    if(std::is_same<T, TNIObject>::value)                       return TNI_CLASS_OBJECT;
    if(std::is_same<T, TNIString>::value)                       return TNI_CLASS_STRING;
    if(std::is_same<T, TNIArray>::value)                        return TNI_CLASS_ARRAY;
    if(std::is_same<T, TNIContext>::value)                      return TNI_CLASS_CONTEXT;
    if(std::is_same<T, TNILibrary>::value)                      return TNI_CLASS_LIBRARY;
    if(std::is_same<T, TNIStream>::value)                       return TNI_CLASS_STREAM;
    if(std::is_same<T, TNIGraphics>::value)                     return TNI_CLASS_GRAPHICS;
    if(std::is_same<T, TNIVector>::value)                       return TNI_CLASS_VECTOR;
    if(std::is_same<T, TNIAssetID>::value)                      return TNI_CLASS_ASSETID;
    if(std::is_same<T, TNILabel>::value)                        return TNI_CLASS_LABEL;
    if(std::is_same<T, TNIBuffer>::value)                       return TNI_CLASS_BUFFER;
    if(std::is_same<T, TNISoup>::value)                         return TNI_CLASS_SOUP;
    if(std::is_same<T, TNIInteger>::value)                      return TNI_CLASS_INTEGER;
    if(std::is_same<T, TNIFloat>::value)                        return TNI_CLASS_FLOAT;
    if(std::is_same<T, TNICoordinates>::value)                  return TNI_CLASS_COORDINATES;
    if(std::is_same<T, TNIHandle>::value)                       return TNI_CLASS_HANDLE;
    if(std::is_same<T, TNIPhysicsVehicle>::value)               return TNI_CLASS_PHYSICS_VEHICLE;
    if(std::is_same<T, TNIPhysicsVehicleFrameSnapshot>::value)  return TNI_CLASS_PHYSICS_VEHICLE_FRAME_SNAPSHOT;
    if(std::is_same<T, TNIPhysicsEngineSpec>::value)            return TNI_CLASS_PHYSICS_ENGINE_SPEC;
    if(std::is_same<T, TNIPhysicsEngineSpecSteam>::value)       return TNI_CLASS_PHYSICS_STEAMENGINE_SPEC;

    return TNI_CLASS_NONE;
}


template <class T>
inline TNIRef<const T> TNICast(TNIRefParam<const TNIObject> object)
{
    if (!object || TNIGetObjectClass(object) != TNI_typeid<T>())
        return nullptr;

    return TNIRef<T>::Reference((T*)object.c_obj());
}

//explicit instantiation
template TNIRef<const TNIString>            TNICast<TNIString>          (TNIRefParam<const TNIObject> object);
template TNIRef<const TNIArray>             TNICast<TNIArray>           (TNIRefParam<const TNIObject> object);
template TNIRef<const TNILibrary>           TNICast<TNILibrary>         (TNIRefParam<const TNIObject> object);
template TNIRef<const TNIVector>            TNICast<TNIVector>          (TNIRefParam<const TNIObject> object);
template TNIRef<const TNIAssetID>           TNICast<TNIAssetID>         (TNIRefParam<const TNIObject> object);
template TNIRef<const TNILabel>             TNICast<TNILabel>           (TNIRefParam<const TNIObject> object);
template TNIRef<const TNIBuffer>            TNICast<TNIBuffer>          (TNIRefParam<const TNIObject> object);
template TNIRef<const TNISoup>              TNICast<TNISoup>            (TNIRefParam<const TNIObject> object);
template TNIRef<const TNIInteger>           TNICast<TNIInteger>         (TNIRefParam<const TNIObject> object);
template TNIRef<const TNIFloat>             TNICast<TNIFloat>           (TNIRefParam<const TNIObject> object);
template TNIRef<const TNICoordinates>       TNICast<TNICoordinates>     (TNIRefParam<const TNIObject> object);
template TNIRef<const TNIHandle>            TNICast<TNIHandle>          (TNIRefParam<const TNIObject> object);
template TNIRef<const TNIPhysicsVehicle>    TNICast<TNIPhysicsVehicle>  (TNIRefParam<const TNIObject> object);

template <class T>
inline TNIRef<T> TNICastMutable(TNIRefParam<const TNIObject> object)
{
    if (!object || TNIGetObjectClass(object) != TNI_typeid<T>())
        return nullptr;

    return TNIRef<T>::Reference((T*)object.c_obj());
}

//explicit instantiation
template TNIRef<TNIArray>                   TNICastMutable<TNIArray>    (TNIRefParam<const TNIObject> object);
template TNIRef<TNIFloat>                   TNICastMutable<TNIFloat>    (TNIRefParam<const TNIObject> object);
template TNIRef<TNIInteger>                 TNICastMutable<TNIInteger>  (TNIRefParam<const TNIObject> object);
template TNIRef<TNIStream>                  TNICastMutable<TNIStream>   (TNIRefParam<const TNIObject> object);


//=============================================================================
// Label/string literals
//=============================================================================


inline TNIRef<TNILabel> operator"" _L_TNI(const char* text, size_t size)
{
    return TNIAllocLabel(text);
}

inline TNIRef<TNIString> operator"" _S_TNI(const char* text, size_t size)
{
    return TNIAllocString(text);
}

#define LABEL(quote) quote##_L_TNI
#define STRING(quote) quote##_S_TNI

#endif //_TNICPPHELPERS_H_