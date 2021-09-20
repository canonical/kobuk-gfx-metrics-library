/*========================== begin_copyright_notice ============================

Copyright (C) 2021 Intel Corporation

SPDX-License-Identifier: MIT

============================= end_copyright_notice ===========================*/

/*
@file ml_sub_device_common.h

@brief Sub device support.
*/

#pragma once

namespace ML
{
    namespace BASE
    {
        //////////////////////////////////////////////////////////////////////////
        /// @brief Base type for SubDeviceCommonTrait object.
        //////////////////////////////////////////////////////////////////////////
        template <typename T>
        struct SubDeviceCommonTrait : TraitObject<T, TT::SubDevice>
        {
            ML_DELETE_DEFAULT_COPY_AND_MOVE( SubDeviceCommonTrait );

            //////////////////////////////////////////////////////////////////////////
            /// @brief Types.
            //////////////////////////////////////////////////////////////////////////
            using Base = TraitObject<T, TT::SubDevice>;

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Members.
            //////////////////////////////////////////////////////////////////////////
            TT::Context& m_Context;
            uint32_t     m_SubDeviceIndex;
            uint32_t     m_SubDeviceCount;
            bool         m_IsSubDevice;
            bool         m_Enabled;

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Device constructor.
            /// @param  context metrics library context.
            //////////////////////////////////////////////////////////////////////////
            SubDeviceCommonTrait( TT::Context& context )
                : Base()
                , m_Context( context )
                , m_SubDeviceIndex( context.m_ClientOptions.m_SubDeviceIndex )
                , m_SubDeviceCount( context.m_ClientOptions.m_SubDeviceCount )
                , m_IsSubDevice( context.m_ClientOptions.m_IsSubDevice )
                , m_Enabled( false )
            {
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Returns description about itself.
            /// @return trait name used in library's code.
            //////////////////////////////////////////////////////////////////////////
            ML_INLINE static const std::string GetDescription()
            {
                return "SubDeviceCommonTrait<Traits>";
            }

            //////////////////////////////////////////////////////////////////////////
            /// @brief  Initializes device data.
            /// @return operation status.
            //////////////////////////////////////////////////////////////////////////
            StatusCode Initialize()
            {
                ML_FUNCTION_LOG( StatusCode::Success );
                return log.m_Result;
            }
        };
    } // namespace BASE

    namespace GEN9
    {
        //////////////////////////////////////////////////////////////////////////
        /// @brief Gen9 type for SubDeviceCommonTrait object.
        //////////////////////////////////////////////////////////////////////////
        template <typename T>
        struct SubDeviceCommonTrait : BASE::SubDeviceCommonTrait<T>
        {
            ML_DECLARE_TRAIT( SubDeviceCommonTrait, BASE );
        };
    } // namespace GEN9

    namespace GEN11
    {
        template <typename T>
        struct SubDeviceCommonTrait : GEN9::SubDeviceCommonTrait<T>
        {
            ML_DECLARE_TRAIT( SubDeviceCommonTrait, GEN9 );
        };
    } // namespace GEN11

    namespace XE_LP
    {
        template <typename T>
        struct SubDeviceCommonTrait : GEN11::SubDeviceCommonTrait<T>
        {
            ML_DECLARE_TRAIT( SubDeviceCommonTrait, GEN11 );
        };
    } // namespace XE_LP
} // namespace ML
