// Copyright (c) Microsoft Corporation. All rights reserved.
//
// Licensed under the MIT License. See LICENSE.txt in the project root for license information.

#pragma once

namespace ProjectUtil {
namespace UI {
namespace Composition {

    // Wrapper class that can be provided to the CompositionImage creation functions
    // to specify the desired size of the decoded bitmap.
    [Windows::Foundation::Metadata::WebHostHidden]
    public ref class CompositionImageOptions sealed
    {
    public:
        CompositionImageOptions();

        property int DecodeWidth
        {
            int get();
            void set(int);
        };

        property int DecodeHeight
        {
            int get();
            void set(int);
        };

    private:
        int _decodeWidth;
        int _decodeHeight;
    };

} // Composition
} // UI
} // ProjectUtil
