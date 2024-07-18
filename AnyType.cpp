#include "AnyType.h"

AnyType::AnyType(const AnyType& other) : m_type(other.m_type) {
    switch (m_type) {
    case Type::Int: m_value.intValue = other.m_value.intValue; break;
    case Type::Double: m_value.doubleValue = other.m_value.doubleValue; break;
    case Type::Bool: m_value.boolValue = other.m_value.boolValue; break;
    case Type::Char: m_value.charValue = other.m_value.charValue; break;
    case Type::UnsignedInt: m_value.uintValue = other.m_value.uintValue; break;
    case Type::Float: m_value.floatValue = other.m_value.floatValue; break;
    case Type::Short: m_value.shortValue = other.m_value.shortValue; break;
    case Type::Long: m_value.longValue = other.m_value.longValue; break;
    case Type::LongLong: m_value.longLongValue = other.m_value.longLongValue; break;
    case Type::UnsignedShort: m_value.ushortValue = other.m_value.ushortValue; break;
    case Type::UnsignedLong: m_value.ulongValue = other.m_value.ulongValue; break;
    case Type::UnsignedLongLong: m_value.ulongLongValue = other.m_value.ulongLongValue; break;
    case Type::SignedChar: m_value.scharValue = other.m_value.scharValue; break;
    case Type::UnsignedChar: m_value.ucharValue = other.m_value.ucharValue; break;
    case Type::Wchar_t: m_value.wcharValue = other.m_value.wcharValue; break;
    case Type::Char16_t: m_value.char16Value = other.m_value.char16Value; break;
    case Type::Char32_t: m_value.char32Value = other.m_value.char32Value; break;
    case Type::None: break;
    }
}

AnyType& AnyType::operator=(const AnyType& other) {
    if (this != &other) {
        destroyValue();
        m_type = other.m_type;
        switch (m_type) {
        case Type::Int: m_value.intValue = other.m_value.intValue; break;
        case Type::Double: m_value.doubleValue = other.m_value.doubleValue; break;
        case Type::Bool: m_value.boolValue = other.m_value.boolValue; break;
        case Type::Char: m_value.charValue = other.m_value.charValue; break;
        case Type::UnsignedInt: m_value.uintValue = other.m_value.uintValue; break;
        case Type::Float: m_value.floatValue = other.m_value.floatValue; break;
        case Type::Short: m_value.shortValue = other.m_value.shortValue; break;
        case Type::Long: m_value.longValue = other.m_value.longValue; break;
        case Type::LongLong: m_value.longLongValue = other.m_value.longLongValue; break;
        case Type::UnsignedShort: m_value.ushortValue = other.m_value.ushortValue; break;
        case Type::UnsignedLong: m_value.ulongValue = other.m_value.ulongValue; break;
        case Type::UnsignedLongLong: m_value.ulongLongValue = other.m_value.ulongLongValue; break;
        case Type::SignedChar: m_value.scharValue = other.m_value.scharValue; break;
        case Type::UnsignedChar: m_value.ucharValue = other.m_value.ucharValue; break;
        case Type::Wchar_t: m_value.wcharValue = other.m_value.wcharValue; break;
        case Type::Char16_t: m_value.char16Value = other.m_value.char16Value; break;
        case Type::Char32_t: m_value.char32Value = other.m_value.char32Value; break;
        case Type::None: break;
        }
    }
    return *this;
}

AnyType& AnyType::operator=(AnyType&& other) noexcept {
    if (this != &other) {
        destroyValue();
        m_type = other.m_type;
        m_value = other.m_value;
        other.m_type = Type::None;
    }
    return *this;
}


std::string AnyType::type_name() const {
    switch (m_type) {
    case Type::Int: return "int";
    case Type::Double: return "double";
    case Type::Bool: return "bool";
    case Type::Char: return "char";
    case Type::UnsignedInt: return "unsigned int";
    case Type::Float: return "float";
    case Type::Short: return "short";
    case Type::Long: return "long";
    case Type::LongLong: return "long long";
    case Type::UnsignedShort: return "unsigned short";
    case Type::UnsignedLong: return "unsigned long";
    case Type::UnsignedLongLong: return "unsigned long long";
    case Type::SignedChar: return "signed char";
    case Type::UnsignedChar: return "unsigned char";
    case Type::Wchar_t: return "wchar_t";
    case Type::Char16_t: return "char16_t";
    case Type::Char32_t: return "char32_t";
    case Type::None: return "none";
    }
    return "unknown";
}

void AnyType::swap(AnyType& other) noexcept {
    std::swap(m_type, other.m_type);
    std::swap(m_value, other.m_value);
}