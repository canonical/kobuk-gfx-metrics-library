/*========================== begin_copyright_notice ============================

Copyright (C) 2020-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

/*
@file ml_debug_helper.h

@brief Auto-generated file. Contains debug functions to print out all library data types.

DO NOT EDIT

Script file:        Tools/MetricsLibraryGenerator/generators/generate_umd.py
Script function:    generate_debug
Template:           Tools/MetricsLibraryGenerator/templates/debug.h
*/

#pragma once

namespace ML
{
    //////////////////////////////////////////////////////////////////////////
    /// @brief The flags used to format a string.
    //////////////////////////////////////////////////////////////////////////
    enum class FormatFlag : uint32_t
    {
        Default,                // Use format predefined in the Metrics Library.

        // Independent flags (switch on):
        BoolAlpha,              // Alphanumerical bool values.
        ShowBase,               // Show numerical base prefixes.
        ShowDecimalPoint,       // Show decimal point.
        ShowPositiveSigns,      // Show positive signs.
        SkipWhitespaces,        // Skip whitespaces.
        FlushAfterInsertions,   // Flush buffer after insertions.
        UpperCase,              // Generate upper-case letters.

        // Independent flags (switch off):
        NoBoolAlpha,            // No alphanumerical bool values.
        NoBase,                 // Do not show numerical base prefixes.
        NoDecimalPoint,         // Do not show decimal point.
        NoPositiveSigns,        // Do not show positive signs.
        NoSkipWhitespaces,      // Do not skip whitespaces.
        NoForceFlush,           // Do not force flushes after insertions.
        NoUpperCase,            // Do not generate upper case letters.

        // Numerical base format flags ("basefield" flags):
        Decimal,                // Use decimal base.
        Hexadecimal,            // Use hexadecimal base.
        Octal,                  // Use octal base.

        // Floating-point format flags ("floatfield" flags):
        Fixed,                  // Use fixed floating-point notation.
        Scientific,             // Use scientific floating-point notation.

        // Adjustment format flags ("adjustfield" flags):
        AdjustInternal,         // Adjust field by inserting characters at an internal position.
        AdjustLeft,             // Adjust output to the left.
        AdjustRight,            // Adjust output to the right.

        // Sets the field width to be used on output operations.
        SetWidth2,              // Sets the field width to 2.
        SetWidth3,              // Sets the field width to 3.
        SetWidth4,              // Sets the field width to 4.
        SetWidth5,              // Sets the field width to 5.
    };

    namespace BASE
    {
        //////////////////////////////////////////////////////////////////////////
        /// @brief Base type for DebugTrait object.
        //////////////////////////////////////////////////////////////////////////
        template <typename T>
        struct DebugTrait
        {
            ML_DELETE_DEFAULT_CONSTRUCTOR( DebugTrait );
            ML_DELETE_DEFAULT_COPY_AND_MOVE( DebugTrait );

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Returns description about itself.
            /// @return trait name used in library's code.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static const std::string GetDescription()
            {
                return "Debug<Traits>";
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Returns the length of the name of the current function.
            /// @return function name length.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static uint32_t& GetFunctionNameLength()
            {
                static uint32_t length = 0;
                return length;
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Returns the string formatting state.
            /// @return formatting state.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::ostringstream& GetFormat()
            {
                static std::ostringstream format;
                return format;
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Returns the indicator of default format usage.
            /// @return indicator of default format usage.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static bool& UseDefaultFormat()
            {
                static bool useDefault = true;
                return useDefault;
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Returns an indent level.
            /// @return current level of indent.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static uint32_t& GetIndentLevel()
            {
                static uint32_t indentLevel = 0;
                return indentLevel;
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief Increments an indent level.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static void IncrementIndentLevel()
            {
                uint32_t& indent = GetIndentLevel();

                if( ( ++indent ) > Constants::Log::m_MaxIndent )
                {
                    indent = Constants::Log::m_MaxIndent;
                }
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief Decrements an indent level.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static void DecrementIndentLevel()
            {
                uint32_t& indent = GetIndentLevel();

                if( indent > 0 )
                {
                    --indent;
                }
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Returns functions names map.
            /// @return map of functions names.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::unordered_map<std::string, std::string>& GetFunctionNamesMap()
            {
                static std::unordered_map<std::string, std::string> functionNamesMap;
                return functionNamesMap;
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief Enumerations.
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Modifies the string formatting state.
            /// @param  flag    a given flag to set.
            /// @return         the string formatting state.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const FormatFlag flag )
            {
                std::ostringstream& format = GetFormat();

                switch( flag )
                {
                    case FormatFlag::BoolAlpha:
                        format << std::boolalpha;
                        break;

                    case FormatFlag::ShowBase:
                        format << std::showbase;
                        break;

                    case FormatFlag::ShowDecimalPoint:
                        format << std::showpoint;
                        break;

                    case FormatFlag::ShowPositiveSigns:
                        format << std::showpos;
                        break;

                    case FormatFlag::SkipWhitespaces:
                        format << std::skipws;
                        break;

                    case FormatFlag::FlushAfterInsertions:
                        format << std::unitbuf;
                        break;

                    case FormatFlag::UpperCase:
                        format << std::uppercase;
                        break;

                    case FormatFlag::NoBoolAlpha:
                        format << std::noboolalpha;
                        break;

                    case FormatFlag::NoBase:
                        format << std::noshowbase;
                        break;

                    case FormatFlag::NoDecimalPoint:
                        format << std::noshowpoint;
                        break;

                    case FormatFlag::NoPositiveSigns:
                        format << std::noshowpos;
                        break;

                    case FormatFlag::NoSkipWhitespaces:
                        format << std::noskipws;
                        break;

                    case FormatFlag::NoForceFlush:
                        format << std::nounitbuf;
                        break;

                    case FormatFlag::NoUpperCase:
                        format << std::nouppercase;
                        break;

                    case FormatFlag::Decimal:
                        format << std::dec;
                        break;

                    case FormatFlag::Hexadecimal:
                        format << std::hex;
                        break;

                    case FormatFlag::Octal:
                        format << std::oct;
                        break;

                    case FormatFlag::Fixed:
                        format << std::fixed;
                        break;

                    case FormatFlag::Scientific:
                        format << std::scientific;
                        break;

                    case FormatFlag::AdjustInternal:
                        format << std::internal;
                        break;

                    case FormatFlag::AdjustLeft:
                        format << std::left;
                        break;

                    case FormatFlag::AdjustRight:
                        format << std::right;
                        break;

                    case FormatFlag::SetWidth2:
                        format << std::setw( 2 );
                        break;

                    case FormatFlag::SetWidth3:
                        format << std::setw( 3 );
                        break;

                    case FormatFlag::SetWidth4:
                        format << std::setw( 4 );
                        break;

                    case FormatFlag::SetWidth5:
                        format << std::setw( 5 );
                        break;

                    case FormatFlag::Default:
                        format << std::noboolalpha << std::noshowbase << std::noshowpoint
                               << std::noshowpos << std::noskipws << std::nounitbuf
                               << std::nouppercase << std::right << std::dec
                               << std::defaultfloat << std::setw( 1 );
                        UseDefaultFormat() = true;
                        break;

                    default:
                        break;
                }

                UseDefaultFormat() = ( flag == FormatFlag::Default );
                return "";
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientApi value )
            {
                std::ostringstream output;
                output << "ClientApi"
                       << "( ";

                switch( value )
                {
                    case ClientApi::Last:
                        output << "Last";
                        break;

                    case ClientApi::OneApi:
                        output << "OneApi";
                        break;

                    case ClientApi::OpenCL:
                        output << "OpenCL";
                        break;

                    case ClientApi::Unknown:
                        output << "Unknown";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientGen value )
            {
                std::ostringstream output;
                output << "ClientGen"
                       << "( ";

                switch( value )
                {
                    case ClientGen::Gen10:
                        output << "Gen10";
                        break;

                #if ML_ENABLE_GEN11
                    case ClientGen::Gen11:
                        output << "Gen11";
                        break;
                #endif

                #if ML_ENABLE_GEN11
                    case ClientGen::Gen11LP:
                        output << "Gen11LP";
                        break;
                #endif

                #if ML_ENABLE_XE_LP
                    case ClientGen::Gen12:
                        output << "Gen12";
                        break;
                #endif

                #if ML_ENABLE_GEN9
                    case ClientGen::Gen9:
                        output << "Gen9";
                        break;
                #endif

                #if ML_ENABLE_GEN9
                    case ClientGen::Gen9LP:
                        output << "Gen9LP";
                        break;
                #endif

                    case ClientGen::Last:
                        output << "Last";
                        break;

                    case ClientGen::Unknown:
                        output << "Unknown";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientOptionsType value )
            {
                std::ostringstream output;
                output << "ClientOptionsType"
                       << "( ";

                switch( value )
                {
                    case ClientOptionsType::Compute:
                        output << "Compute";
                        break;

                    case ClientOptionsType::Last:
                        output << "Last";
                        break;

                    case ClientOptionsType::Posh:
                        output << "Posh";
                        break;

                    case ClientOptionsType::Ptbr:
                        output << "Ptbr";
                        break;

                    case ClientOptionsType::SubDevice:
                        output << "SubDevice";
                        break;

                    case ClientOptionsType::SubDeviceCount:
                        output << "SubDeviceCount";
                        break;

                    case ClientOptionsType::SubDeviceIndex:
                        output << "SubDeviceIndex";
                        break;

                    case ClientOptionsType::Tbs:
                        output << "Tbs";
                        break;

                    case ClientOptionsType::WorkloadPartition:
                        output << "WorkloadPartition";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const GpuCommandBufferType value )
            {
                std::ostringstream output;
                output << "GpuCommandBufferType"
                       << "( ";

                switch( value )
                {
                    case GpuCommandBufferType::Compute:
                        output << "Compute";
                        break;

                    case GpuCommandBufferType::Last:
                        output << "Last";
                        break;

                    case GpuCommandBufferType::Posh:
                        output << "Posh";
                        break;

                    case GpuCommandBufferType::Render:
                        output << "Render";
                        break;

                    case GpuCommandBufferType::Tile:
                        output << "Tile";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const GpuConfigurationActivationType value )
            {
                std::ostringstream output;
                output << "GpuConfigurationActivationType"
                       << "( ";

                switch( value )
                {
                    case GpuConfigurationActivationType::EscapeCode:
                        output << "EscapeCode";
                        break;

                    case GpuConfigurationActivationType::Last:
                        output << "Last";
                        break;

                    case GpuConfigurationActivationType::Tbs:
                        output << "Tbs";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const LinuxAdapterType value )
            {
                std::ostringstream output;
                output << "LinuxAdapterType"
                       << "( ";

                switch( value )
                {
                    case LinuxAdapterType::DrmFileDescriptor:
                        output << "DrmFileDescriptor";
                        break;

                    case LinuxAdapterType::Last:
                        output << "Last";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const MemoryFlags value )
            {
                std::ostringstream output;
                output << "MemoryFlags"
                       << "( ";

                switch( value )
                {
                    case MemoryFlags::Cachable:
                        output << "Cachable";
                        break;

                    case MemoryFlags::Linear:
                        output << "Linear";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const MemoryType value )
            {
                std::ostringstream output;
                output << "MemoryType"
                       << "( ";

                switch( value )
                {
                    case MemoryType::CommandBuffer:
                        output << "CommandBuffer";
                        break;

                    case MemoryType::Cpu:
                        output << "Cpu";
                        break;

                    case MemoryType::Last:
                        output << "Last";
                        break;

                    case MemoryType::Query:
                        output << "Query";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ObjectType value )
            {
                std::ostringstream output;
                output << "ObjectType"
                       << "( ";

                switch( value )
                {
                    case ObjectType::ConfigurationHwCountersOa:
                        output << "ConfigurationHwCountersOa";
                        break;

                    case ObjectType::ConfigurationHwCountersUser:
                        output << "ConfigurationHwCountersUser";
                        break;

                    case ObjectType::Context:
                        output << "Context";
                        break;

                    case ObjectType::Last:
                        output << "Last";
                        break;

                    case ObjectType::MarkerStreamUser:
                        output << "MarkerStreamUser";
                        break;

                    case ObjectType::MarkerStreamUserExtended:
                        output << "MarkerStreamUserExtended";
                        break;

                    case ObjectType::OverrideDisablePoshPrimitives:
                        output << "OverrideDisablePoshPrimitives";
                        break;

                    case ObjectType::OverrideFlushCaches:
                        output << "OverrideFlushCaches";
                        break;

                    case ObjectType::OverrideNullHardware:
                        output << "OverrideNullHardware";
                        break;

                    case ObjectType::OverridePoshQuery:
                        output << "OverridePoshQuery";
                        break;

                    case ObjectType::OverrideUser:
                        output << "OverrideUser";
                        break;

                    case ObjectType::QueryHwCounters:
                        output << "QueryHwCounters";
                        break;

                    case ObjectType::QueryHwCountersCopyReports:
                        output << "QueryHwCountersCopyReports";
                        break;

                    case ObjectType::QueryPipelineTimestamps:
                        output << "QueryPipelineTimestamps";
                        break;

                    case ObjectType::Unknown:
                        output << "Unknown";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ParameterType value )
            {
                std::ostringstream output;
                output << "ParameterType"
                       << "( ";

                switch( value )
                {
                    case ParameterType::Last:
                        output << "Last";
                        break;

                    case ParameterType::LibraryBuildNumber:
                        output << "LibraryBuildNumber";
                        break;

                    case ParameterType::QueryHwCountersReportApiSize:
                        output << "QueryHwCountersReportApiSize";
                        break;

                    case ParameterType::QueryHwCountersReportGpuSize:
                        output << "QueryHwCountersReportGpuSize";
                        break;

                    case ParameterType::QueryPipelineTimestampsReportApiSize:
                        output << "QueryPipelineTimestampsReportApiSize";
                        break;

                    case ParameterType::QueryPipelineTimestampsReportGpuSize:
                        output << "QueryPipelineTimestampsReportGpuSize";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const StatusCode value )
            {
                std::ostringstream output;
                output << "StatusCode"
                       << "( ";

                switch( value )
                {
                    case StatusCode::CannotOpenFile:
                        output << "CannotOpenFile";
                        break;

                    case StatusCode::Failed:
                        output << "Failed";
                        break;

                    case StatusCode::IncorrectObject:
                        output << "IncorrectObject";
                        break;

                    case StatusCode::IncorrectParameter:
                        output << "IncorrectParameter";
                        break;

                    case StatusCode::IncorrectSlot:
                        output << "IncorrectSlot";
                        break;

                    case StatusCode::IncorrectVersion:
                        output << "IncorrectVersion";
                        break;

                    case StatusCode::InsufficientSpace:
                        output << "InsufficientSpace";
                        break;

                    case StatusCode::Last:
                        output << "Last";
                        break;

                    case StatusCode::NotImplemented:
                        output << "NotImplemented";
                        break;

                    case StatusCode::NotInitialized:
                        output << "NotInitialized";
                        break;

                    case StatusCode::NotSupported:
                        output << "NotSupported";
                        break;

                    case StatusCode::NullPointer:
                        output << "NullPointer";
                        break;

                    case StatusCode::OutOfMemory:
                        output << "OutOfMemory";
                        break;

                    case StatusCode::ReportContextSwitchLost:
                        output << "ReportContextSwitchLost";
                        break;

                    case StatusCode::ReportInconsistent:
                        output << "ReportInconsistent";
                        break;

                    case StatusCode::ReportLost:
                        output << "ReportLost";
                        break;

                    case StatusCode::ReportNotReady:
                        output << "ReportNotReady";
                        break;

                    case StatusCode::ReportWithoutWorkload:
                        output << "ReportWithoutWorkload";
                        break;

                    case StatusCode::Success:
                        output << "Success";
                        break;

                    case StatusCode::TbsUnableToEnable:
                        output << "TbsUnableToEnable";
                        break;

                    case StatusCode::TbsUnableToRead:
                        output << "TbsUnableToRead";
                        break;

                    case StatusCode::UnknownGen:
                        output << "UnknownGen";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator to a string that contains the
            ///         enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ValueType value )
            {
                std::ostringstream output;
                output << "ValueType"
                       << "( ";

                switch( value )
                {
                    case ValueType::Bool:
                        output << "Bool";
                        break;

                    case ValueType::Double:
                        output << "Double";
                        break;

                    case ValueType::Float:
                        output << "Float";
                        break;

                    case ValueType::Int16:
                        output << "Int16";
                        break;

                    case ValueType::Int32:
                        output << "Int32";
                        break;

                    case ValueType::Int64:
                        output << "Int64";
                        break;

                    case ValueType::Int8:
                        output << "Int8";
                        break;

                    case ValueType::Last:
                        output << "Last";
                        break;

                    case ValueType::String:
                        output << "String";
                        break;

                    case ValueType::Uint16:
                        output << "Uint16";
                        break;

                    case ValueType::Uint32:
                        output << "Uint32";
                        break;

                    case ValueType::Uint64:
                        output << "Uint64";
                        break;

                    case ValueType::Uint8:
                        output << "Uint8";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }

                output << " )";
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator of oa buffer type enumeration to
            ///         a string that contains the enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const TT::Layouts::OaBuffer::Type value )
            {
                std::ostringstream output;
                output << "OaBufferType"
                       << "( ";

                switch( value )
                {
                    case T::Layouts::OaBuffer::Type::Oa:
                        output << "Oa";
                        break;

                    case T::Layouts::OaBuffer::Type::ContextSwitch:
                        output << "ContextSwitch";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }
                output << " )";

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator of get data mode enumeration to
            ///         a string that contains the enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( TT::Layouts::HwCounters::Query::GetDataMode value )
            {
                std::ostringstream output;
                output << "HwCounters::Query::GetDataMode"
                       << "( ";

                switch( value )
                {
                    case T::Layouts::HwCounters::Query::GetDataMode::Normal:
                        output << "Normal";
                        break;

                    case T::Layouts::HwCounters::Query::GetDataMode::Multisampled:
                        output << "Multisampled";
                        break;

                    case T::Layouts::HwCounters::Query::GetDataMode::Extended:
                        output << "Extended";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint64_t>( value );
                        output << " (" << std::dec << static_cast<uint64_t>( value ) << ")";
                        break;
                }
                output << " )";

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator of oa buffer sampling type enumeration
            ///         to a string that contains the enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const TT::Layouts::OaBuffer::SamplingType& value )
            {
                std::ostringstream output;
                output << "Layouts::OaBuffer::SamplingType"
                       << "( ";

                switch( value )
                {
                    case T::Layouts::OaBuffer::SamplingType::Disabled:
                        output << "Disabled";
                        break;

                    case T::Layouts::OaBuffer::SamplingType::Tbs:
                        output << "Tbs";
                        break;

                    case T::Layouts::OaBuffer::SamplingType::QueryMultisampled:
                        output << "QueryMultisampled";
                        break;

                    case T::Layouts::OaBuffer::SamplingType::QueryExtended:
                        output << "QueryExtended";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint64_t>( value );
                        output << " (" << std::dec << static_cast<uint64_t>( value ) << ")";
                        break;
                }
                output << " )";

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator of report collecting mode enumeration
            ///         to a string that contains the enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const TT::Layouts::HwCounters::Query::ReportCollectingMode value )
            {
                std::ostringstream output;
                output << "HwCounters::Query::ReportCollectingMode"
                       << "( ";

                switch( value )
                {
                    case T::Layouts::HwCounters::Query::ReportCollectingMode::ReportPerformanceCounters:
                        output << "ReportPerformanceCounters";
                        break;

                    case T::Layouts::HwCounters::Query::ReportCollectingMode::StoreRegisterMemoryOar:
                        output << "StoreRegisterMemoryOar";
                        break;

                    case T::Layouts::HwCounters::Query::ReportCollectingMode::StoreRegisterMemoryOag:
                        output << "StoreRegisterMemoryOag";
                        break;

                    case T::Layouts::HwCounters::Query::ReportCollectingMode::TriggerOag:
                        output << "TriggerOag";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }
                output << " )";

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an enumerator of log type enumeration to a string
            ///         that contains the enumerator name.
            /// @param  value   a given enumerator to convert.
            /// @return         converted enumerator name to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const LogType value )
            {
                std::ostringstream output;
                output << "LogType"
                       << "( ";

                switch( value )
                {
                    case LogType::Critical:
                        output << "Critical";
                        break;

                    case LogType::Error:
                        output << "Error";
                        break;

                    case LogType::Warning:
                        output << "Warning";
                        break;

                    case LogType::Info:
                        output << "Info";
                        break;

                    case LogType::Debug:
                        output << "Debug";
                        break;

                    case LogType::Traits:
                        output << "Traits";
                        break;

                    case LogType::Entered:
                        output << "Entered";
                        break;

                    case LogType::Exiting:
                        output << "Exiting";
                        break;

                    case LogType::Input:
                        output << "Input";
                        break;

                    case LogType::Output:
                        output << "Output";
                        break;

                    default:
                        output << "Illegal value: " << std::hex << std::showbase << static_cast<uint32_t>( value );
                        output << " (" << std::dec << static_cast<uint32_t>( value ) << ")";
                        break;
                }
                output << " )";

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief Reports.
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Creates oa report log.
            /// @param  oaReport    a given oa report.
            /// @return             string that contains formatted oa report log.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const TT::Layouts::HwCounters::ReportOa& oaReport )
            {
                std::ostringstream output;
                output << "OA: ";
                output << "rsn = " << std::setw( Constants::Log::m_MaxReportReasonLength ) << oaReport.m_Header.m_ReportId.m_ReportReason;
                output << std::hex << std::showbase;
                output << ", rid = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Header.m_ReportId.m_Value;
                output << ", tsp = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Header.m_Timestamp;
                output << ", cid = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Header.m_ContextId;
                output << ", tic = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Header.m_GpuTicks;
                output << ", oa0 = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Data.m_OaCounter[0];
                output << ", oa1 = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Data.m_OaCounter[1];
                output << ", oa6 = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Data.m_OaCounter[6];
                output << ", oa7 = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Data.m_OaCounter[7];
                output << ", oa8 = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Data.m_OaCounter[8];
                output << ", noa0 = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Data.m_NoaCounter[0];
                output << ", noa1 = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Data.m_NoaCounter[1];
                output << ", noa2 = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Data.m_NoaCounter[2];
                output << ", noa13 = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Data.m_NoaCounter[13];
                output << ", noa14 = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Data.m_NoaCounter[14];
                output << ", noa15 = " << std::setw( Constants::Log::m_MaxUint32Length ) << oaReport.m_Data.m_NoaCounter[15];
                output << "; ";

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Creates api report log.
            /// @param  userReport  a given api report.
            /// @return             string that contains formatted api report log.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const TT::Layouts::HwCounters::Query::ReportApi& userReport )
            {
                std::ostringstream output;
                std::string        flags;

                flags += userReport.m_Flags.m_ReportLost              ? " lost"              : "";
                flags += userReport.m_Flags.m_ReportInconsistent      ? " inconsistent"      : "";
                flags += userReport.m_Flags.m_ReportNotReady          ? " not_ready"         : "";
                flags += userReport.m_Flags.m_ReportContextSwitchLost ? " no_context_switch" : "";
                flags += userReport.m_Flags.m_ReportWithoutWorkload   ? " no_workload      " : "";
                flags  = flags.length() ? flags : "none";

                output << "QUERY: ";
                output << std::hex << std::showbase;
                output << "time = " << std::setw( Constants::Log::m_MaxUint64Length ) << userReport.m_TotalTime;
                output << ", tic = " << std::setw( Constants::Log::m_MaxUint64Length ) << userReport.m_GpuTicks;
                output << ", oa0 = " << std::setw( Constants::Log::m_MaxUint64Length ) << userReport.m_OaCounter[0];
                output << ", oa1 = " << std::setw( Constants::Log::m_MaxUint64Length ) << userReport.m_OaCounter[1];
                output << ", noa0 = " << std::setw( Constants::Log::m_MaxUint64Length ) << userReport.m_NoaCounter[0];
                output << ", noa1 = " << std::setw( Constants::Log::m_MaxUint64Length ) << userReport.m_NoaCounter[1];
                output << ", noa2 = " << std::setw( Constants::Log::m_MaxUint64Length ) << userReport.m_NoaCounter[2];
                output << ", noa3 = " << std::setw( Constants::Log::m_MaxUint64Length ) << userReport.m_NoaCounter[3];
                output << ", mark = " << std::setw( Constants::Log::m_MaxUint64Length ) << userReport.m_MarkerUser;
                output << ", flags = " << flags;
                output << "; ";

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Creates global purpose counters report log.
            /// @param  gpReport    a given global purpose report.
            /// @return             string that contains formatted global purpose
            ///                     counters report log.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const TT::Layouts::HwCounters::ReportGp& gpReport )
            {
                std::ostringstream output;
                output << "GP: ";
                output << std::hex << std::showbase;
                output << "gp1 = " << std::setw( Constants::Log::m_MaxUint64Length ) << gpReport.m_Counter1;
                output << ", gp2 = " << std::setw( Constants::Log::m_MaxUint64Length ) << gpReport.m_Counter2;
                output << "; ";

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Creates report reason log.
            /// @param  reportReason    a given report reason.
            /// @return                 string that contains formatted report reason.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const TT::Layouts::OaBuffer::ReportReason reportReason )
            {
                std::ostringstream output;

                switch( reportReason )
                {
                    case T::Layouts::OaBuffer::ReportReason::Timer:
                        output << "Timer";
                        break;

                    case T::Layouts::OaBuffer::ReportReason::User1:
                        output << "User1";
                        break;

                    case T::Layouts::OaBuffer::ReportReason::User2:
                        output << "User2";
                        break;

                    case T::Layouts::OaBuffer::ReportReason::ContextSwitch:
                        output << "ContextSwitch";
                        break;

                    case T::Layouts::OaBuffer::ReportReason::C6:
                        output << "C6";
                        break;

                    case T::Layouts::OaBuffer::ReportReason::FrequencyChange:
                        output << "FrequencyChange";
                        break;

                    case T::Layouts::OaBuffer::ReportReason::DmaSampling:
                        output << "DmaSampling";
                        break;

                    default:
                        output << "Illegal report reason: " << std::hex << std::showbase << static_cast<uint32_t>( reportReason );
                        output << " (" << std::dec << static_cast<uint32_t>( reportReason ) << ")";
                        break;
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts a boolean value to a string.
            /// @param  value   a given boolean value to convert.
            /// @return         converted boolean value to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const bool value )
            {
                return value ? "true" : "false";
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts a floating-point value to a string.
            /// @param  value   a given floating-point value to convert.
            /// @return         converted floating-point value to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const float value )
            {
                return std::to_string( value );
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Creates a empty string.
            /// @return empty string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString()
            {
                std::string output = "";
                return output;
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts a pointer value to a string.
            /// @param  value   a given pointer value to convert.
            /// @return         converted pointer value to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const void* value )
            {
                std::ostringstream output;

                if( UseDefaultFormat() )
                {
                    output << "0x" << std::setfill( '0' ) << std::setw( sizeof( void* ) * 2 ) << std::hex << reinterpret_cast<uintptr_t>( value );
                }
                else
                {
                    output.flags( GetFormat().flags() );
                    output.width( GetFormat().width() );
                    output << reinterpret_cast<uintptr_t>( value );
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an array of characters to a string.
            /// @param  value   a given array of characters to convert.
            /// @return         converted array of characters to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const char* value )
            {
                std::ostringstream output;

                if( value )
                {
                    output << value;
                }
                else
                {
                    output << "0x" << std::setfill( '0' ) << std::setw( sizeof( void* ) * 2 ) << std::hex << reinterpret_cast<uintptr_t>( value );
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts an array of characters to a string.
            /// @param  value   a given array of characters to convert.
            /// @return         converted array of characters to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const unsigned char* value )
            {
                std::ostringstream output;

                if( value )
                {
                    output << value;
                }
                else
                {
                    output << "0x" << std::setfill( '0' ) << std::setw( sizeof( void* ) * 2 ) << std::hex << reinterpret_cast<uintptr_t>( value );
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts a numeric value to a string.
            /// @param  value   a given numeric value to convert.
            /// @return         converted numeric value to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const uint8_t value )
            {
                std::ostringstream output;

                if( UseDefaultFormat() )
                {
                    if( Constants::Log::m_ShowHexadecimal )
                    {
                        output << "0x" << std::setfill( '0' ) << std::setw( sizeof( value ) * 2 ) << std::hex << value;
                    }

                    if( Constants::Log::m_ShowDecimal )
                    {
                        output << ( Constants::Log::m_ShowHexadecimal ? " = " : "" );
                        output << std::dec << value;
                    }
                }
                else
                {
                    output.flags( GetFormat().flags() );
                    output.width( GetFormat().width() );
                    output << value;
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts a numeric value to a string.
            /// @param  value   a given numeric value to convert.
            /// @return         converted numeric value to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const uint16_t value )
            {
                std::ostringstream output;

                if( UseDefaultFormat() )
                {
                    if( Constants::Log::m_ShowHexadecimal )
                    {
                        output << "0x" << std::setfill( '0' ) << std::setw( sizeof( value ) * 2 ) << std::hex << value;
                    }

                    if( Constants::Log::m_ShowDecimal )
                    {
                        output << ( Constants::Log::m_ShowHexadecimal ? " = " : "" );
                        output << std::dec << value;
                    }
                }
                else
                {
                    output.flags( GetFormat().flags() );
                    output.width( GetFormat().width() );
                    output << value;
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts a numeric value to a string.
            /// @param  value   a given numeric value to convert.
            /// @return         converted numeric value to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const uint32_t value )
            {
                std::ostringstream output;

                if( UseDefaultFormat() )
                {
                    if( Constants::Log::m_ShowHexadecimal )
                    {
                        output << "0x" << std::setfill( '0' ) << std::setw( sizeof( value ) * 2 ) << std::hex << value;
                    }

                    if( Constants::Log::m_ShowDecimal )
                    {
                        output << ( Constants::Log::m_ShowHexadecimal ? " = " : "" );
                        output << std::dec << value;
                    }
                }
                else
                {
                    output.flags( GetFormat().flags() );
                    output.width( GetFormat().width() );
                    output << value;
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts a numeric value to a string.
            /// @param  value   a given numeric value to convert.
            /// @return         converted numeric value to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const uint64_t value )
            {
                std::ostringstream output;

                if( UseDefaultFormat() )
                {
                    if( Constants::Log::m_ShowHexadecimal )
                    {
                        output << "0x" << std::setfill( '0' ) << std::setw( sizeof( value ) * 2 ) << std::hex << value;
                    }

                    if( Constants::Log::m_ShowDecimal )
                    {
                        output << ( Constants::Log::m_ShowHexadecimal ? " = " : "" );
                        output << std::dec << value;
                    }
                }
                else
                {
                    output.flags( GetFormat().flags() );
                    output.width( GetFormat().width() );
                    output << value;
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts a numeric value to a string.
            /// @param  value   a given numeric value to convert.
            /// @return         converted numeric value to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const int8_t value )
            {
                std::ostringstream output;

                if( UseDefaultFormat() )
                {
                    if( Constants::Log::m_ShowHexadecimal )
                    {
                        output << "0x" << std::setfill( '0' ) << std::setw( sizeof( value ) * 2 ) << std::hex << value;
                    }

                    if( Constants::Log::m_ShowDecimal )
                    {
                        output << ( Constants::Log::m_ShowHexadecimal ? " = " : "" );
                        output << std::dec << value;
                    }
                }
                else
                {
                    output.flags( GetFormat().flags() );
                    output.width( GetFormat().width() );
                    output << value;
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts a numeric value to a string.
            /// @param  value   a given numeric value to convert.
            /// @return         converted numeric value to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const int16_t value )
            {
                std::ostringstream output;

                if( UseDefaultFormat() )
                {
                    if( Constants::Log::m_ShowHexadecimal )
                    {
                        output << "0x" << std::setfill( '0' ) << std::setw( sizeof( value ) * 2 ) << std::hex << value;
                    }

                    if( Constants::Log::m_ShowDecimal )
                    {
                        output << ( Constants::Log::m_ShowHexadecimal ? " = " : "" );
                        output << std::dec << value;
                    }
                }
                else
                {
                    output.flags( GetFormat().flags() );
                    output.width( GetFormat().width() );
                    output << value;
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts a numeric value to a string.
            /// @param  value   a given numeric value to convert.
            /// @return         converted numeric value to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const int32_t value )
            {
                std::ostringstream output;

                if( UseDefaultFormat() )
                {
                    if( Constants::Log::m_ShowHexadecimal )
                    {
                        output << "0x" << std::setfill( '0' ) << std::setw( sizeof( value ) * 2 ) << std::hex << value;
                    }

                    if( Constants::Log::m_ShowDecimal )
                    {
                        output << ( Constants::Log::m_ShowHexadecimal ? " = " : "" );
                        output << std::dec << value;
                    }
                }
                else
                {
                    output.flags( GetFormat().flags() );
                    output.width( GetFormat().width() );
                    output << value;
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts a numeric value to a string.
            /// @param  value   a given numeric value to convert.
            /// @return         converted numeric value to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const int64_t value )
            {
                std::ostringstream output;

                if( UseDefaultFormat() )
                {
                    if( Constants::Log::m_ShowHexadecimal )
                    {
                        output << "0x" << std::setfill( '0' ) << std::setw( sizeof( value ) * 2 ) << std::hex << value;
                    }

                    if( Constants::Log::m_ShowDecimal )
                    {
                        output << ( Constants::Log::m_ShowHexadecimal ? " = " : "" );
                        output << std::dec << value;
                    }
                }
                else
                {
                    output.flags( GetFormat().flags() );
                    output.width( GetFormat().width() );
                    output << value;
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Passes through a given string.
            /// @param  value   a given string.
            /// @return         passed through string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const std::string& value )
            {
                return value;
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief Structures.
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientCallbacks_1_0& value )
            {
                std::ostringstream output;
                output << "ClientCallbacks_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "CommandBufferFlush               ", value.CommandBufferFlush );
                output << MemberToString( "CommandBufferHasSpace            ", value.CommandBufferHasSpace );
                output << MemberToString( "CommandBufferGetSpace            ", value.CommandBufferGetSpace );
                output << MemberToString( "GpuMemoryAllocate                ", value.GpuMemoryAllocate );
                output << MemberToString( "GpuMemoryPatch                   ", value.GpuMemoryPatch );
                output << MemberToString( "GpuMemoryRelease                 ", value.GpuMemoryRelease );
                output << MemberToString( "CpuMemoryAllocate                ", value.CpuMemoryAllocate );
                output << MemberToString( "CpuMemoryRelease                 ", value.CpuMemoryRelease );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientDataLinuxAdapter_1_0& value )
            {
                std::ostringstream output;
                output << "ClientDataLinuxAdapter_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Type                         ", value.Type );
                output << MemberToString( "DrmFileDescriptor            ", value.DrmFileDescriptor );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientDataLinux_1_0& value )
            {
                std::ostringstream output;
                output << "ClientDataLinux_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Adapter            ", value.Adapter );
                output << MemberToString( "Reserved           ", reinterpret_cast<uintptr_t>( value.Reserved ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientDataWindows_1_0& )
            {
                return "";
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientData_1_0& value )
            {
                std::ostringstream output;
                output << "ClientData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Handle                         ", value.Handle );
                output << MemberToString( "Windows                        ", value.Windows );
                output << MemberToString( "Linux                          ", value.Linux );
                output << MemberToString( "ClientOptions                  ", value.ClientOptions );
                output << MemberToString( "ClientOptionsCount             ", value.ClientOptionsCount );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientHandle_1_0& value )
            {
                std::ostringstream output;
                output << "ClientHandle_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "data           ", reinterpret_cast<uintptr_t>( value.data ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientMemoryHandle_1_0& value )
            {
                std::ostringstream output;
                output << "ClientMemoryHandle_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "data           ", reinterpret_cast<uintptr_t>( value.data ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientOptionsComputeData_1_0& value )
            {
                std::ostringstream output;
                output << "ClientOptionsComputeData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Asynchronous           ", value.Asynchronous );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientOptionsData_1_0& value )
            {
                std::ostringstream output;
                output << "ClientOptionsData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Type                         ", value.Type );

                switch( value.Type )
                {
                    case ClientOptionsType::Posh:
                        output << MemberToString( "Posh                         ", value.Posh );
                        break;

                    case ClientOptionsType::Ptbr:
                        output << MemberToString( "Ptbr                         ", value.Ptbr );
                        break;

                    case ClientOptionsType::Compute:
                        output << MemberToString( "Compute                      ", value.Compute );
                        break;

                    case ClientOptionsType::Tbs:
                        output << MemberToString( "Tbs                          ", value.Tbs );
                        break;

                    case ClientOptionsType::SubDevice:
                        output << MemberToString( "SubDevice                    ", value.SubDevice );
                        break;

                    case ClientOptionsType::SubDeviceIndex:
                        output << MemberToString( "SubDeviceIndex               ", value.SubDeviceIndex );
                        break;

                    case ClientOptionsType::SubDeviceCount:
                        output << MemberToString( "SubDeviceCount               ", value.SubDeviceCount );
                        break;

                    case ClientOptionsType::WorkloadPartition:
                        output << MemberToString( "WorkloadPartition            ", value.WorkloadPartition );
                        break;

                    default:
                        output << "Not known member.\n";
                        break;
                }

                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientOptionsPoshData_1_0& value )
            {
                std::ostringstream output;
                output << "ClientOptionsPoshData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Enabled          ", value.Enabled );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientOptionsPtbrData_1_0& value )
            {
                std::ostringstream output;
                output << "ClientOptionsPtbrData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Enabled          ", value.Enabled );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientOptionsSubDeviceCountData_1_0& value )
            {
                std::ostringstream output;
                output << "ClientOptionsSubDeviceCountData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Count            ", value.Count );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientOptionsSubDeviceData_1_0& value )
            {
                std::ostringstream output;
                output << "ClientOptionsSubDeviceData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Enabled          ", value.Enabled );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientOptionsSubDeviceIndexData_1_0& value )
            {
                std::ostringstream output;
                output << "ClientOptionsSubDeviceIndexData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Index            ", value.Index );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientOptionsTbsData_1_0& value )
            {
                std::ostringstream output;
                output << "ClientOptionsTbsData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Enabled          ", value.Enabled );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientOptionsWorkloadPartition_1_0& value )
            {
                std::ostringstream output;
                output << "ClientOptionsWorkloadPartition_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Enabled          ", value.Enabled );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ClientType_1_0& value )
            {
                std::ostringstream output;
                output << "ClientType_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Api          ", value.Api );
                output << MemberToString( "Gen          ", value.Gen );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const CommandBufferData_1_0& value )
            {
                std::ostringstream output;
                output << "CommandBufferData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "HandleContext                          ", value.HandleContext );
                output << MemberToString( "CommandsType                           ", value.CommandsType );
                output << MemberToString( "Type                                   ", value.Type );
                output << MemberToString( "Allocation                             ", value.Allocation );
                output << MemberToString( "Data                                   ", reinterpret_cast<uintptr_t>( value.Data ) );
                output << MemberToString( "Size                                   ", value.Size );
                output << MemberToString( "Offset                                 ", value.Offset );

                switch( value.CommandsType )
                {
                    case ObjectType::QueryHwCounters:
                        output << MemberToString( "QueryHwCounters                        ", value.QueryHwCounters );
                        break;

                    case ObjectType::QueryHwCountersCopyReports:
                        output << MemberToString( "QueryHwCountersCopyReports             ", value.QueryHwCountersCopyReports );
                        break;

                    case ObjectType::QueryPipelineTimestamps:
                        output << MemberToString( "QueryPipelineTimestamps                ", value.QueryPipelineTimestamps );
                        break;

                    case ObjectType::OverrideDisablePoshPrimitives:
                        output << MemberToString( "Override                               ", value.Override );
                        break;

                    case ObjectType::OverrideFlushCaches:
                        output << MemberToString( "Override                               ", value.Override );
                        break;

                    case ObjectType::OverrideNullHardware:
                        output << MemberToString( "Override                               ", value.Override );
                        break;

                    case ObjectType::OverridePoshQuery:
                        output << MemberToString( "Override                               ", value.Override );
                        break;

                    case ObjectType::OverrideUser:
                        output << MemberToString( "Override                               ", value.Override );
                        break;

                    case ObjectType::MarkerStreamUser:
                        output << MemberToString( "MarkerStreamUser                       ", value.MarkerStreamUser );
                        break;

                    case ObjectType::MarkerStreamUserExtended:
                        output << MemberToString( "MarkerStreamUserExtended               ", value.MarkerStreamUserExtended );
                        break;

                    default:
                        output << "Not known member.\n";
                        break;
                }

                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const CommandBufferMarkerStreamUserExtended_1_0& value )
            {
                std::ostringstream output;
                output << "CommandBufferMarkerStreamUserExtended_1_0:" << '\n';
                IncrementIndentLevel();
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const CommandBufferMarkerStreamUser_1_0& value )
            {
                std::ostringstream output;
                output << "CommandBufferMarkerStreamUser_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Reserved           ", value.Reserved );
                output << MemberToString( "Value              ", value.Value );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const CommandBufferOverride_1_0& value )
            {
                std::ostringstream output;
                output << "CommandBufferOverride_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Handle             ", value.Handle );
                output << MemberToString( "Enable             ", value.Enable );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const CommandBufferQueryHwCountersCopyReports_1_0& value )
            {
                std::ostringstream output;
                output << "CommandBufferQueryHwCountersCopyReports_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "HandleSource             ", value.HandleSource );
                output << MemberToString( "HandleTarget             ", value.HandleTarget );
                output << MemberToString( "AddressSource            ", value.AddressSource );
                output << MemberToString( "AddressTarget            ", value.AddressTarget );
                output << MemberToString( "SlotSource               ", value.SlotSource );
                output << MemberToString( "SlotTarget               ", value.SlotTarget );
                output << MemberToString( "SlotCount                ", value.SlotCount );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const CommandBufferQueryHwCounters_1_0& value )
            {
                std::ostringstream output;
                output << "CommandBufferQueryHwCounters_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Handle                           ", value.Handle );
                output << MemberToString( "HandleUserConfiguration          ", value.HandleUserConfiguration );
                output << MemberToString( "Slot                             ", value.Slot );
                output << MemberToString( "MarkerUser                       ", value.MarkerUser );
                output << MemberToString( "MarkerDriver                     ", value.MarkerDriver );
                output << MemberToString( "EndTag                           ", value.EndTag );
                output << MemberToString( "Begin                            ", value.Begin );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const CommandBufferQueryPipelineTimestamps_1_0& value )
            {
                std::ostringstream output;
                output << "CommandBufferQueryPipelineTimestamps_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Handle             ", value.Handle );
                output << MemberToString( "EndTag             ", value.EndTag );
                output << MemberToString( "Begin              ", value.Begin );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const CommandBufferSize_1_0& value )
            {
                std::ostringstream output;
                output << "CommandBufferSize_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "GpuMemorySize                    ", value.GpuMemorySize );
                output << MemberToString( "GpuMemoryPatchesCount            ", value.GpuMemoryPatchesCount );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ConfigurationActivateData_1_0& value )
            {
                std::ostringstream output;
                output << "ConfigurationActivateData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Type           ", value.Type );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ConfigurationCreateData_1_0& value )
            {
                std::ostringstream output;
                output << "ConfigurationCreateData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "HandleContext            ", value.HandleContext );
                output << MemberToString( "Type                     ", value.Type );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ConfigurationHandle_1_0& value )
            {
                std::ostringstream output;
                output << "ConfigurationHandle_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "data           ", reinterpret_cast<uintptr_t>( value.data ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ContextCreateData_1_0& value )
            {
                std::ostringstream output;
                output << "ContextCreateData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "ClientData               ", value.ClientData );
                output << MemberToString( "ClientCallbacks          ", value.ClientCallbacks );
                output << MemberToString( "Api                      ", value.Api );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const ContextHandle_1_0& value )
            {
                std::ostringstream output;
                output << "ContextHandle_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "data           ", reinterpret_cast<uintptr_t>( value.data ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const CpuMemoryAllocateData_1_0& value )
            {
                std::ostringstream output;
                output << "CpuMemoryAllocateData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Size           ", value.Size );
                output << MemberToString( "Data           ", reinterpret_cast<uintptr_t>( value.Data ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const GetReportData_1_0& value )
            {
                std::ostringstream output;
                output << "GetReportData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Type               ", value.Type );

                switch( value.Type )
                {
                    case ObjectType::QueryHwCounters:
                        output << MemberToString( "Query              ", value.Query );
                        break;

                    case ObjectType::QueryHwCountersCopyReports:
                        output << MemberToString( "Query              ", value.Query );
                        break;

                    case ObjectType::QueryPipelineTimestamps:
                        output << MemberToString( "Query              ", value.Query );
                        break;

                    case ObjectType::OverrideDisablePoshPrimitives:
                        output << MemberToString( "Override           ", value.Override );
                        break;

                    case ObjectType::OverrideFlushCaches:
                        output << MemberToString( "Override           ", value.Override );
                        break;

                    case ObjectType::OverrideNullHardware:
                        output << MemberToString( "Override           ", value.Override );
                        break;

                    case ObjectType::OverridePoshQuery:
                        output << MemberToString( "Override           ", value.Override );
                        break;

                    case ObjectType::OverrideUser:
                        output << MemberToString( "Override           ", value.Override );
                        break;

                    default:
                        output << "Not known member.\n";
                        break;
                }

                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const GetReportOverride_1_0& value )
            {
                std::ostringstream output;
                output << "GetReportOverride_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Handle             ", value.Handle );
                output << MemberToString( "DataSize           ", value.DataSize );
                output << MemberToString( "Data               ", reinterpret_cast<uintptr_t>( value.Data ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const GetReportQuery_1_0& value )
            {
                std::ostringstream output;
                output << "GetReportQuery_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Handle                 ", value.Handle );
                output << MemberToString( "Slot                   ", value.Slot );
                output << MemberToString( "SlotsCount             ", value.SlotsCount );
                output << MemberToString( "DataSize               ", value.DataSize );
                output << MemberToString( "Data                   ", reinterpret_cast<uintptr_t>( value.Data ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const GpuMemoryAllocateData_1_0& value )
            {
                std::ostringstream output;
                output << "GpuMemoryAllocateData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Type             ", value.Type );
                output << MemberToString( "Flags            ", value.Flags );
                output << MemberToString( "Size             ", value.Size );
                output << MemberToString( "Data             ", reinterpret_cast<uintptr_t>( value.Data ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const GpuMemory_1_0& value )
            {
                std::ostringstream output;
                output << "GpuMemory_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "GpuAddress             ", value.GpuAddress );
                output << MemberToString( "CpuAddress             ", reinterpret_cast<uintptr_t>( value.CpuAddress ) );
                output << MemberToString( "HandleMemory           ", value.HandleMemory );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const Interface_1_0& value )
            {
                std::ostringstream output;
                output << "Interface_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "GetParameter                     ", value.GetParameter );
                output << MemberToString( "CommandBufferGet                 ", value.CommandBufferGet );
                output << MemberToString( "CommandBufferGetSize             ", value.CommandBufferGetSize );
                output << MemberToString( "QueryCreate                      ", value.QueryCreate );
                output << MemberToString( "QueryDelete                      ", value.QueryDelete );
                output << MemberToString( "OverrideCreate                   ", value.OverrideCreate );
                output << MemberToString( "OverrideDelete                   ", value.OverrideDelete );
                output << MemberToString( "MarkerCreate                     ", value.MarkerCreate );
                output << MemberToString( "MarkerDelete                     ", value.MarkerDelete );
                output << MemberToString( "ConfigurationCreate              ", value.ConfigurationCreate );
                output << MemberToString( "ConfigurationActivate            ", value.ConfigurationActivate );
                output << MemberToString( "ConfigurationDeactivate          ", value.ConfigurationDeactivate );
                output << MemberToString( "ConfigurationDelete              ", value.ConfigurationDelete );
                output << MemberToString( "GetData                          ", value.GetData );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const MarkerCreateData_1_0& value )
            {
                std::ostringstream output;
                output << "MarkerCreateData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "HandleContext            ", value.HandleContext );
                output << MemberToString( "Type                     ", value.Type );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const MarkerHandle_1_0& value )
            {
                std::ostringstream output;
                output << "MarkerHandle_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "data           ", reinterpret_cast<uintptr_t>( value.data ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const OverrideCreateData_1_0& value )
            {
                std::ostringstream output;
                output << "OverrideCreateData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "HandleContext            ", value.HandleContext );
                output << MemberToString( "Type                     ", value.Type );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const OverrideHandle_1_0& value )
            {
                std::ostringstream output;
                output << "OverrideHandle_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "data           ", reinterpret_cast<uintptr_t>( value.data ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const QueryCreateData_1_0& value )
            {
                std::ostringstream output;
                output << "QueryCreateData_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "HandleContext            ", value.HandleContext );
                output << MemberToString( "Type                     ", value.Type );
                output << MemberToString( "Slots                    ", value.Slots );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const QueryHandle_1_0& value )
            {
                std::ostringstream output;
                output << "QueryHandle_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "data           ", reinterpret_cast<uintptr_t>( value.data ) );
                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Converts all structure members values to a string.
            /// @param  value   a given structure to convert.
            /// @return         converted all members values to string.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static std::string ToString( const TypedValue_1_0& value )
            {
                std::ostringstream output;
                output << "TypedValue_1_0:" << '\n';
                IncrementIndentLevel();
                output << MemberToString( "Type                 ", value.Type );

                switch( value.Type )
                {
                    case ValueType::Int8:
                        output << MemberToString( "ValueInt8            ", value.ValueInt8 );
                        break;

                    case ValueType::Uint8:
                        output << MemberToString( "ValueUInt8           ", value.ValueUInt8 );
                        break;

                    case ValueType::Int16:
                        output << MemberToString( "ValueInt16           ", value.ValueInt16 );
                        break;

                    case ValueType::Uint16:
                        output << MemberToString( "ValueUInt16          ", value.ValueUInt16 );
                        break;

                    case ValueType::Int32:
                        output << MemberToString( "ValueInt32           ", value.ValueInt32 );
                        break;

                    case ValueType::Uint32:
                        output << MemberToString( "ValueUInt32          ", value.ValueUInt32 );
                        break;

                    case ValueType::Int64:
                        output << MemberToString( "ValueInt64           ", value.ValueInt64 );
                        break;

                    case ValueType::Uint64:
                        output << MemberToString( "ValueUInt64          ", value.ValueUInt64 );
                        break;

                    case ValueType::Float:
                        output << MemberToString( "ValueFloat           ", value.ValueFloat );
                        break;

                    case ValueType::Bool:
                        output << MemberToString( "ValueBool            ", value.ValueBool );
                        break;

                    case ValueType::String:
                        output << MemberToString( "ValueString          ", value.ValueString );
                        break;

                    default:
                        output << "Not known member.\n";
                        break;
                }

                DecrementIndentLevel();
                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Validates a given pointer and prints an error message out if
            ///         the pointer is null.
            /// @param  value   a given pointer.
            /// @param  output  an output string stream.
            /// @return         true if the pointer is not null, false otherwise.
            //////////////////////////////////////////////////////////////////////////
            template <typename ValueT>
            ML_INLINE static std::string ToString( const ValueT* value )
            {
                std::ostringstream output;

                if( UseDefaultFormat() )
                {
                    if( value != nullptr && !std::is_void<ValueT>::value && !std::is_function<ValueT>::value )
                    {
                        output << T::Debug::ToString( *value );
                    }
                    else
                    {
                        output << "0x" << std::setfill( '0' ) << std::setw( sizeof( void* ) * 2 ) << std::hex << reinterpret_cast<uintptr_t>( value );
                    }
                }
                else
                {
                    output.flags( GetFormat().flags() );
                    output.width( GetFormat().width() );
                    output << reinterpret_cast<uintptr_t>( value );
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Creates a string that contains a member name of the structure
            ///         with its value.
            /// @param  parameterName   a given name of the member.
            /// @param  value           a given value of the member.
            /// @return                 created string.
            //////////////////////////////////////////////////////////////////////////
            template <typename ValueT>
            ML_INLINE static std::string MemberToString( const char* parameterName, const ValueT value )
            {
                std::ostringstream output;
                const uint32_t     indent                = GetIndentLevel();
                const uint32_t     parameterNameLength   = static_cast<uint32_t>( strlen( parameterName ) );
                const uint32_t     functionNameLength    = GetFunctionNameLength();
                const uint32_t     functionNameLengthMax = Constants::Log::m_MaxFunctionNameLength;
                const uint32_t     functionNameAlignment = std::max<uint32_t>( functionNameLength, functionNameLengthMax );
                const uint32_t     messageLength         = Constants::Log::m_IndentSize * indent + functionNameAlignment + parameterNameLength;

                // Apply indentation.
                for( uint32_t i = 0; i < indent; ++i )
                {
                    output << Constants::Log::m_ScopeCharacter << std::setw( Constants::Log::m_IndentSize - 1 ) << ' ';
                }

                // Print the parameter name and add a single space to avoid arguments concatenation.
                output << parameterName << ' ';

                // Apply alignment.
                if( messageLength < Constants::Log::m_MaxMessageLength )
                {
                    output << std::setw( Constants::Log::m_MaxMessageLength - messageLength ) << ' ';
                }

                // Print value.
                output << T::Debug::ToString( value );

                // Add a new line if needed.
                if( output.str().back() != '\n' )
                {
                    output << '\n';
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Validates a given pointer and prints an error message out if
            ///         the pointer is null.
            /// @param  value   a given pointer.
            /// @param  output  an output string stream.
            /// @return         true if the pointer is not null, false otherwise.
            //////////////////////////////////////////////////////////////////////////
            template <typename ValueT>
            ML_INLINE static bool ValidatePointer( ValueT value, std::ostringstream& output )
            {
                if( value == nullptr )
                {
                    output << "ERROR: null pointer";
                    return false;
                }

                return true;
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Creates a string that contains an array member name of
            ///         the structure with its value.
            /// @param  arrayName   a given array name of the member.
            /// @param  value       a given array value of the member.
            /// @param  padding     element padding.
            /// @param  arraySize   size of a given array.
            /// @return             created string.
            //////////////////////////////////////////////////////////////////////////
            template <typename ValueT>
            ML_INLINE static std::string MemberToStringArray( const char* arrayName, const ValueT value, const char* padding, const int arraySize )
            {
                std::ostringstream output;
                const uint32_t     indent = GetIndentLevel();

                for( uint32_t i = 0; i < indent; ++i )
                {
                    output << Constants::Log::m_ScopeCharacter << std::setw( Constants::Log::m_IndentSize - 1 ) << ' ';
                }

                output << arrayName << padding;
                output << "0x" << std::setfill( '0' ) << std::setw( sizeof( void* ) * 2 ) << std::hex << ( uintptr_t )( value );
                output << " (" << std::dec << ( uintptr_t )( value ) << ")";
                output << " --> \n";

                if( arraySize > 0 )
                {
                    if( ValidatePointer( value, output ) )
                    {
                        for( int i = 0; i < arraySize; i++ )
                        {
                            for( uint32_t i = 0; i < indent; ++i )
                            {
                                output << Constants::Log::m_ScopeCharacter << std::setw( Constants::Log::m_IndentSize - 1 ) << ' ';
                            }
                            output << arrayName << "[" << i << "]" << padding << T::Debug::ToString( value[i] );
                        }
                    }
                }

                if( output.str().back() != '\n' )
                {
                    output << '\n';
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief Helper / miscellaneous.
            //////////////////////////////////////////////////////////////////////////

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Formats logs.
            /// @param  values  a given values to format.
            /// @return         formatted string.
            //////////////////////////////////////////////////////////////////////////
            template <typename... Values>
            ML_INLINE static std::string Format( const Values&... values )
            {
                uint32_t                 index  = 0;
                const uint32_t           indent = GetIndentLevel();
                std::vector<std::string> unpackedValues( sizeof...( values ) );
                std::ostringstream       output;

                (void) std::initializer_list<int>{ ( unpackedValues[index++] = T::Debug::ToString( values ), 0 )... };

                if( index > 0 )
                {
                    auto           value                 = unpackedValues.begin();
                    const uint32_t functionNameLength    = GetFunctionNameLength();
                    const uint32_t functionNameLengthMax = Constants::Log::m_MaxFunctionNameLength;
                    const uint32_t functionNameAlignment = std::max<uint32_t>( functionNameLength, functionNameLengthMax );
                    const uint32_t messageLength         = static_cast<uint32_t>( value->size() ) + Constants::Log::m_IndentSize * indent + functionNameAlignment;

                    // Apply indentation.
                    for( uint32_t i = 0; i < indent; ++i )
                    {
                        output << Constants::Log::m_ScopeCharacter << std::setw( Constants::Log::m_IndentSize - 1 ) << ' ';
                    }

                    // Print the first argument (usually it is a name).
                    output << *value;

                    // Apply alignment (before printing the next arguments).
                    if( index > 1 )
                    {
                        if( messageLength < Constants::Log::m_MaxMessageLength )
                        {
                            output << std::setw( Constants::Log::m_MaxMessageLength - messageLength ) << ' ';
                        }
                    }

                    // Print all remaining arguments.
                    while( ++value != unpackedValues.end() )
                    {
                        if( value->size() > 0 )
                        {
                            // Single space has been added to avoid arguments concatenation.
                            output << ' ';
                        }
                        output << *value;
                    }

                    // Restore default ML format.
                    T::Debug::ToString( FormatFlag::Default );
                }

                return output.str();
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief Prints oa report csv log.
            /// @param oaReport a given oa report.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static void ToCsv( const TT::Layouts::HwCounters::ReportOa& oaReport )
            {
                static bool          initialize = true;
                static std::ofstream file       = {};

                if( initialize )
                {
                    if( ML_SUCCESS( T::Tools::OpenCsv( "ReportOa", file ) ) )
                    {
                        file << "ReportId,ReportReason,ContextValid,Timestamp,ContextId,GpuTicks,";

                        for( uint32_t i = 0; i < T::Layouts::HwCounters::m_OaCountersCount; ++i )
                        {
                            file << "OaCounter" << i << ',';
                        }

                        for( uint32_t i = 0; i < T::Layouts::HwCounters::m_NoaCountersCount; ++i )
                        {
                            file << "NoaCounter" << i << ',';
                        }

                        file << '\n';

                        initialize = false;
                    }
                }

                if( file.is_open() )
                {
                    file << oaReport.m_Header.m_ReportId.m_Value << ',';
                    file << oaReport.m_Header.m_ReportId.m_ReportReason << ',';
                    file << oaReport.m_Header.m_ReportId.m_ContextValid << ',';
                    file << oaReport.m_Header.m_Timestamp << ',';
                    file << oaReport.m_Header.m_ContextId << ',';
                    file << oaReport.m_Header.m_GpuTicks << ',';

                    for( uint32_t i = 0; i < T::Layouts::HwCounters::m_OaCountersCount; ++i )
                    {
                        if( i < T::Layouts::HwCounters::m_OaCounters40bitsCount )
                        {
                            file << static_cast<uint64_t>( oaReport.m_Data.m_OaCounter[i] ) + ( static_cast<uint64_t>( oaReport.m_Data.m_OaCounterHB[i] ) << 32 ) << ',';
                        }
                        else
                        {
                            file << oaReport.m_Data.m_OaCounter[i] << ',';
                        }
                    }

                    for( uint32_t i = 0; i < T::Layouts::HwCounters::m_NoaCountersCount; ++i )
                    {
                        file << oaReport.m_Data.m_NoaCounter[i] << ',';
                    }

                    file << '\n';
                }
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief Prints csv logs.
            /// @param values  a given values to print.
            //////////////////////////////////////////////////////////////////////////
            template <typename... Values>
            ML_INLINE static void PrintCsv( const Values&... values )
            {
                (void) std::initializer_list<int>{ ( T::Debug::ToCsv( values ), 0 )... };
            }
        };
    } // namespace BASE

    namespace GEN9
    {
        template <typename T>
        struct DebugTrait : BASE::DebugTrait<T>
        {
            ML_DECLARE_TRAIT( DebugTrait, BASE );
        };
    } // namespace GEN9

    namespace GEN11
    {
        template <typename T>
        struct DebugTrait : GEN9::DebugTrait<T>
        {
            ML_DECLARE_TRAIT( DebugTrait, GEN9 );
        };
    } // namespace GEN11

    namespace XE_LP
    {
        template <typename T>
        struct DebugTrait : GEN11::DebugTrait<T>
        {
            ML_DECLARE_TRAIT( DebugTrait, GEN11 );
        };
    } // namespace XE_LP

} // namespace ML
