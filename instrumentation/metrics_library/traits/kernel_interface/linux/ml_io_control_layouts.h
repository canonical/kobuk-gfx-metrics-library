/*========================== begin_copyright_notice ============================

Copyright (C) 2020-2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

/*
@file ml_io_control_layouts.h

@brief Layout for io controls.
*/

#pragma once

namespace ML
{
    //////////////////////////////////////////////////////////////////////////
    /// @brief Base type for IoControlLayoutsTrait object.
    //////////////////////////////////////////////////////////////////////////
    struct IoControlLayoutsTrait
    {
        ML_DELETE_DEFAULT_CONSTRUCTOR( IoControlLayoutsTrait );
        ML_DELETE_DEFAULT_COPY_AND_MOVE( IoControlLayoutsTrait );

        //////////////////////////////////////////////////////////////////////////
        /// @brief IoControlParameter enumeration.
        //////////////////////////////////////////////////////////////////////////
        enum class IoControlParameter : uint32_t
        {
            PlatformIndex = 12, // GTDI_DEVICE_PARAM_PLATFORM_INDEX
        };

        //////////////////////////////////////////////////////////////////////////
        /// @brief  Returns description about itself.
        /// @return trait name used in library's code.
        //////////////////////////////////////////////////////////////////////////
        ML_INLINE static const std::string GetDescription()
        {
            return "IoControlLayoutsTrait (Linux)";
        }
    };
} // namespace ML
