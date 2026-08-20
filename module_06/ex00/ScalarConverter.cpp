#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) 
{
    (void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) 
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

static bool checkChar(const std::string &literal)
{
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        return (1);
    }
    return (0);
}

static bool checkInt(const std::string &literal)
{
    long long i;
    std::stringstream strInt(literal);

    strInt >> i;
    if (strInt.fail() || !strInt.eof())
    {
        return (0);
    }
    return (1); 
}

static bool checkFloat(const std::string &literal)
{
    float f;
    char suffix;
    char suffixAfter;
    std::stringstream strFloat(literal);

    if (literal.find('.') == std::string::npos)
    {
        return (0);
    }
    strFloat >> f >> suffix;
    if (strFloat.fail() || suffix != 'f')
    {
        return (0);
    }
    if (strFloat >> suffixAfter)
    {
        return (0);
    }
    return (1);
}


static bool checkDouble(const std::string &literal)
{
    double d;
    std::stringstream strDouble(literal);

    strDouble >> d;
    if (strDouble.fail() || !strDouble.eof())
    {
        return (0);
    }
    return (1);
}


static bool checkInfNan(const std::string &literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan"
        || literal == "-inff" || literal == "+inff" || literal == "nanf")
        return (1);
    else
        return (0);
}

void ScalarConverter::convertFromChar(const std::string &literal)
{
    char c;
    int i;
    float f;
    double d;

    c = literal[1];
    i = static_cast<int>(c);
    f = static_cast<float>(c);
    d = static_cast<double>(c);

    if (!std::isprint(static_cast<unsigned char>(c)))
    {
        std::cout << "char: " << "Not displayable" << std::endl;
    }
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromInt(const std::string &literal)
{
    char c;
    float f;
    double d;
    long long l;
    std::stringstream strInt(literal);

    strInt >> l;
    c = static_cast<char>(l);
    f = static_cast<float>(l);
    d = static_cast<double>(l);

    if (l > INT_MAX || l < INT_MIN)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }
    if (l < 0 || l > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: Not displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << l << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromFloat(const std::string &literal)
{
    char c;
    int i;
    float f;
    double d;
    std::stringstream strFloat(literal);

    strFloat >> f;
    c = static_cast<char>(f);
    i = static_cast<int>(f);
    f = static_cast<float>(f);
    d = static_cast<double>(f);

    if (f < 0 || f > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: Not displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if (f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
    {
        std::cout << "int: impossible" << std::endl;
    }
    else
        std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromDouble(const std::string &literal)
{
    char c;
    int i;
    float f;
    double d;
    std::stringstream strDouble(literal);

    strDouble >> d;
    c = static_cast<char>(d);
    i = static_cast<int>(d);
    f = static_cast<float>(d);
    d = static_cast<double>(d);

    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: Not displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    if (f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;
    if (d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFromInfNan(const std::string &literal)
{
    if (literal == "+inf" || literal == "+inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "+inff" << std::endl;
        std::cout << "double: " << "+inf" << std::endl;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "-inff" << std::endl;
        std::cout << "double: " << "-inf" << std::endl;
    }
    else if (literal == "nan" || literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "nanf" << std::endl;
        std::cout << "double: " << "nan" << std::endl;
    }
}

void ScalarConverter::convert(const std::string &literal)
{
    if (checkChar(literal))
        convertFromChar(literal);
    else if (checkInfNan(literal))
        convertFromInfNan(literal);
    else if (checkInt(literal))
        convertFromInt(literal);
    else if (checkFloat(literal))
        convertFromFloat(literal);
    else if (checkDouble(literal))
        convertFromDouble(literal);
    else
        std::cerr << "Invalid literal\n";
}