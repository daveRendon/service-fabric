// ------------------------------------------------------------
// Copyright (c) Microsoft Corporation.  All rights reserved.
// Licensed under the MIT License (MIT). See License.txt in the repo root for license information.
// ------------------------------------------------------------

#pragma once

namespace Management
{
    namespace FaultAnalysisService
    {
        class TestErrorEvent 
            : public ChaosEventBase
        {
            DENY_COPY(TestErrorEvent)

        public:
            TestErrorEvent();

            TestErrorEvent(
                Common::DateTime timeStampUtc,
                std::wstring & reason);

            explicit TestErrorEvent(TestErrorEvent &&);

            TestErrorEvent & operator = (TestErrorEvent && other);

            _declspec(property(get = get_Reason)) std::wstring const & Reason;
            std::wstring const & get_Reason() const { return reason_; }

            Common::ErrorCode FromPublicApi(FABRIC_CHAOS_EVENT const &) override;
            Common::ErrorCode ToPublicApi(__in Common::ScopedHeap & heap, __out FABRIC_CHAOS_EVENT &) const override;

            FABRIC_FIELDS_03(
                kind_,
                timeStampUtc_,
                reason_);

            BEGIN_JSON_SERIALIZABLE_PROPERTIES()
                SERIALIZABLE_PROPERTY_CHAIN()
                SERIALIZABLE_PROPERTY(ServiceModel::Constants::Reason, reason_)
            END_JSON_SERIALIZABLE_PROPERTIES()

        private:
            std::wstring reason_;
        };

        DEFINE_CHAOS_EVENT_ACTIVATOR(TestErrorEvent, FABRIC_CHAOS_EVENT_KIND_TEST_ERROR)
    }
}
