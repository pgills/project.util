// Copyright (c) Microsoft Corporation. All rights reserved.
//
// Licensed under the MIT License. See LICENSE.txt in the project root for license information.

#include "pch.h"
#include "CompositionImageOptions.h"

namespace ProjectUtil {
namespace UI {
namespace Composition {

CompositionImageOptions::CompositionImageOptions()
{
}

int CompositionImageOptions::DecodeWidth::get()
{
    return _decodeWidth;
}

void CompositionImageOptions::DecodeWidth::set(int value)
{
    if (value < 0)
    {
        ERR(E_INVALIDARG, L"The DecodeWidth property of CompositionImageOptions cannot be less than 0.");
        __abi_ThrowIfFailed(E_INVALIDARG);
    }

    _decodeWidth = value;
}

int CompositionImageOptions::DecodeHeight::get()
{
    return _decodeHeight;
}

void CompositionImageOptions::DecodeHeight::set(int value)
{
    if (value < 0)
    {
        ERR(E_INVALIDARG, L"The DecodeHeight property of CompositionImageOptions cannot be less than 0.");
        __abi_ThrowIfFailed(E_INVALIDARG);
    }

    _decodeHeight = value;
}

}  // namespace Composition
}  // namespace UI
}  // namespace ProjectUtil