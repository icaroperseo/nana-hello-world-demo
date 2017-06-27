/*
 * File:   hello.cpp
 * 
 * Author: Iván Ruvalcaba
 * Contact: <icaroperseo[at]protonmail[dot]com>
 *
 * Created on June 26, 2017 at 09:23 AM
 * 
 * Language: C++11/14.
 * Compiler: Any Standard C++ compiler(Visual C++ 2013, GCC/MinGW and Clang).
 * OS: GNU/Linux, Microsoft Windows, Mac OS (experimental).
 *
 * Description:
 * 
 * This program displays the classic "Hello, world!" string using Nana C++ GUI
 * library (http://nanapro.org/en-us/).
 * 
 * License:
 *
 * ISC License
 *
 * Copyright (c) 2017, Iván Ruvalcaba
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR
 * IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <nana/gui.hpp>

using namespace nana;

int main()
{
    /*
     * Class: form
     * 
     * The form widget represents a popup window. Overall it is a root widget
     * which attaches the OS/Windowing system's native window.
     */
    form fm;
    // Replaces the default window title for something more descriptive.
    fm.caption("Nana \"Hello World!\" demo");

    /*
     * Class: drawing
     *
     * The class drawing provides interfaces to draw graphics on the surface
     * of a widget. It specifies a drawing method, and then every time the
     * widget redraws, the drawing method will be applied.
     */
    drawing {fm}.draw([](paint::graphics& graph)
    {
        std::string str = "Hello, world!";
        auto str_size = graph.text_extent_size(str);

        graph.string(
            point
            {
                static_cast<int>(graph.width() - str_size.width) / 2,
                static_cast<int>(graph.height() - str_size.height) / 2
            }, str);
    });

    // When instances a form widget, the form window starts immediately.
    // So, the window is created when it constructs.
    fm.show();

    exec();
}
