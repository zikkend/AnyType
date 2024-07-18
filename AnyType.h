#pragma once

#include <string>
#include <stdexcept>
#include <typeinfo>

class AnyType
{
public:
    AnyType() : m_type(Type::None) {}

    AnyType(int val) : m_type(Type::Int) { m_value.intValue = val; }
    AnyType(double val) : m_type(Type::Double) { m_value.doubleValue = val; }
    AnyType(bool val) : m_type(Type::Bool) { m_value.boolValue = val; }
    AnyType(char val) : m_type(Type::Char) { m_value.charValue = val; }
    AnyType(unsigned int val) : m_type(Type::UnsignedInt) { m_value.uintValue = val; }
    AnyType(float val) : m_type(Type::Float) { m_value.floatValue = val; }
    AnyType(short val) : m_type(Type::Short) { m_value.shortValue = val; }
    AnyType(long val) : m_type(Type::Long) { m_value.longValue = val; }
    AnyType(long long val) : m_type(Type::LongLong) { m_value.longLongValue = val; }
    AnyType(unsigned short val) : m_type(Type::UnsignedShort) { m_value.ushortValue = val; }
    AnyType(unsigned long val) : m_type(Type::UnsignedLong) { m_value.ulongValue = val; }
    AnyType(unsigned long long val) : m_type(Type::UnsignedLongLong) { m_value.ulongLongValue = val; }
    AnyType(signed char val) : m_type(Type::SignedChar) { m_value.scharValue = val; }
    AnyType(unsigned char val) : m_type(Type::UnsignedChar) { m_value.ucharValue = val; }
    AnyType(wchar_t val) : m_type(Type::Wchar_t) { m_value.wcharValue = val; }
    AnyType(char16_t val) : m_type(Type::Char16_t) { m_value.char16Value = val; }
    AnyType(char32_t val) : m_type(Type::Char32_t) { m_value.char32Value = val; }

    AnyType(const AnyType& other);

    AnyType(AnyType&& other) noexcept : m_type(other.m_type), m_value(other.m_value) {
        other.m_type = Type::None;
    }

    ~AnyType() {
        destroyValue();
    }

    AnyType& operator=(const AnyType& other);
    AnyType& operator=(AnyType&& other) noexcept;

    AnyType& operator=(int val) { destroyValue(); m_type = Type::Int; m_value.intValue = val; return *this; }
    AnyType& operator=(double val) { destroyValue(); m_type = Type::Double; m_value.doubleValue = val; return *this; }
    AnyType& operator=(bool val) { destroyValue(); m_type = Type::Bool; m_value.boolValue = val; return *this; }
    AnyType& operator=(char val) { destroyValue(); m_type = Type::Char; m_value.charValue = val; return *this; }
    AnyType& operator=(unsigned int val) { destroyValue(); m_type = Type::UnsignedInt; m_value.uintValue = val; return *this; }
    AnyType& operator=(float val) { destroyValue(); m_type = Type::Float; m_value.floatValue = val; return *this; }
    AnyType& operator=(short val) { destroyValue(); m_type = Type::Short; m_value.shortValue = val; return *this; }
    AnyType& operator=(long val) { destroyValue(); m_type = Type::Long; m_value.longValue = val; return *this; }
    AnyType& operator=(long long val) { destroyValue(); m_type = Type::LongLong; m_value.longLongValue = val; return *this; }
    AnyType& operator=(unsigned short val) { destroyValue(); m_type = Type::UnsignedShort; m_value.ushortValue = val; return *this; }
    AnyType& operator=(unsigned long val) { destroyValue(); m_type = Type::UnsignedLong; m_value.ulongValue = val; return *this; }
    AnyType& operator=(unsigned long long val) { destroyValue(); m_type = Type::UnsignedLongLong; m_value.ulongLongValue = val; return *this; }
    AnyType& operator=(signed char val) { destroyValue(); m_type = Type::SignedChar; m_value.scharValue = val; return *this; }
    AnyType& operator=(unsigned char val) { destroyValue(); m_type = Type::UnsignedChar; m_value.ucharValue = val; return *this; }
    AnyType& operator=(wchar_t val) { destroyValue(); m_type = Type::Wchar_t; m_value.wcharValue = val; return *this; }
    AnyType& operator=(char16_t val) { destroyValue(); m_type = Type::Char16_t; m_value.char16Value = val; return *this; }
    AnyType& operator=(char32_t val) { destroyValue(); m_type = Type::Char32_t; m_value.char32Value = val; return *this; }

    std::string type_name() const;
    void swap(AnyType& other) noexcept;

    template<typename T>
    T get() const {
        throw std::bad_cast();
    }

    template<>
    int get<int>() const {
        if (m_type != Type::Int) throw std::bad_cast();
        return m_value.intValue;
    }

    template<>
    double get<double>() const {
        if (m_type != Type::Double) throw std::bad_cast();
        return m_value.doubleValue;
    }

    template<>
    bool get<bool>() const {
        if (m_type != Type::Bool) throw std::bad_cast();
        return m_value.boolValue;
    }

    template<>
    char get<char>() const {
        if (m_type != Type::Char) throw std::bad_cast();
        return m_value.charValue;
    }

    template<>
    unsigned int get<unsigned int>() const {
        if (m_type != Type::UnsignedInt) throw std::bad_cast();
        return m_value.uintValue;
    }

    template<>
    float get<float>() const {
        if (m_type != Type::Float) throw std::bad_cast();
        return m_value.floatValue;
    }

    template<>
    short get<short>() const {
        if (m_type != Type::Short) throw std::bad_cast();
        return m_value.shortValue;
    }

    template<>
    long get<long>() const {
        if (m_type != Type::Long) throw std::bad_cast();
        return m_value.longValue;
    }

    template<>
    long long get<long long>() const {
        if (m_type != Type::LongLong) throw std::bad_cast();
        return m_value.longLongValue;
    }

    template<>
    unsigned short get<unsigned short>() const {
        if (m_type != Type::UnsignedShort) throw std::bad_cast();
        return m_value.ushortValue;
    }

    template<>
    unsigned long get<unsigned long>() const {
        if (m_type != Type::UnsignedLong) throw std::bad_cast();
        return m_value.ulongValue;
    }

    template<>
    unsigned long long get<unsigned long long>() const {
        if (m_type != Type::UnsignedLongLong) throw std::bad_cast();
        return m_value.ulongLongValue;
    }

    template<>
    signed char get<signed char>() const {
        if (m_type != Type::SignedChar) throw std::bad_cast();
        return m_value.scharValue;
    }

    template<>
    unsigned char get<unsigned char>() const {
        if (m_type != Type::UnsignedChar) throw std::bad_cast();
        return m_value.ucharValue;
    }

    template<>
    wchar_t get<wchar_t>() const {
        if (m_type != Type::Wchar_t) throw std::bad_cast();
        return m_value.wcharValue;
    }

    template<>
    char16_t get<char16_t>() const {
        if (m_type != Type::Char16_t) throw std::bad_cast();
        return m_value.char16Value;
    }

    template<>
    char32_t get<char32_t>() const {
        if (m_type != Type::Char32_t) throw std::bad_cast();
        return m_value.char32Value;
    }

private:
    enum class Type {
        Int,
        Double,
        Bool,
        Char,
        UnsignedInt,
        Float,
        Short,
        Long,
        LongLong,
        UnsignedShort,
        UnsignedLong,
        UnsignedLongLong,
        SignedChar,
        UnsignedChar,
        Wchar_t,
        Char16_t,
        Char32_t,
        None
    };

    Type m_type;

    union Value {
        int intValue;
        double doubleValue;
        bool boolValue;
        char charValue;
        unsigned int uintValue;
        float floatValue;
        short shortValue;
        long longValue;
        long long longLongValue;
        unsigned short ushortValue;
        unsigned long ulongValue;
        unsigned long long ulongLongValue;
        signed char scharValue;
        unsigned char ucharValue;
        wchar_t wcharValue;
        char16_t char16Value;
        char32_t char32Value;
    };

    Value m_value;

    void destroyValue()
    {
        m_type = Type::None;
    }
};

