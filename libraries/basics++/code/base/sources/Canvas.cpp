/*
 * CANVAS
 * Copyright © 2018+ Ángel Rodríguez Ballesteros
 *
 * Distributed under the Boost Software License, version  1.0
 * See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
 *
 * angel.rodriguez@esne.edu
 *
 * C1801161300
 */

#include <basics/Canvas>

namespace basics
{

    Id              Canvas::canvas_specialization_ids      [10];
    Canvas::Factory Canvas::canvas_specialization_factories[10];
    size_t          Canvas::canvas_specialization_count = 0;

    Canvas * Canvas::create (Id id, Graphics_Context::Accessor & context, const Options & options)
    {
        Id context_id = context->get_id ();

        for (unsigned index = 0; index < canvas_specialization_count; ++index)
        {
            if (canvas_specialization_ids[index] == context_id)
            {
                return canvas_specialization_factories[index] (id, context, options);
            }
        }

        return nullptr;
    }

}
