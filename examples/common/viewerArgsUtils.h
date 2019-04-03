//
//   Copyright 2019 Pixar
//
//   Licensed under the Apache License, Version 2.0 (the "Apache License")
//   with the following modification; you may not use this file except in
//   compliance with the Apache License and the following modification to it:
//   Section 6. Trademarks. is deleted and replaced with:
//
//   6. Trademarks. This License does not grant permission to use the trade
//      names, trademarks, service marks, or product names of the Licensor
//      and its affiliates, except as required to comply with Section 4(c) of
//      the License and to reproduce the content of the NOTICE file.
//
//   You may obtain a copy of the Apache License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the Apache License with the above modification is
//   distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
//   KIND, either express or implied. See the Apache License for the specific
//   language governing permissions and limitations under the Apache License.
//

#ifndef VIEWER_ARGS_UTILS_H
#define VIEWER_ARGS_UTILS_H

#include "../../regression/common/shape_utils.h"

#include "../common/argOptions.h"
#include "../common/shapeDesc.h"

class ObjAnim;

#include <vector>

namespace ViewerArgsUtils {

// From the list of obj files in args, populates the
// defaultShapes vector, treating the objs as an animated series, returning
// an ObjAnim object.
const ObjAnim *PopulateAnimShapes(const ArgOptions &args, 
                                  std::vector<ShapeDesc> *defaultShapes);

// From the list of obj files in args, populates the
// defaultShapes vector.
void PopulateShapes(const ArgOptions &args,
                    std::vector<ShapeDesc> *defaultShapes);

// From the list of obj files in args, populates the
// defaultShapes vector and the objAnim object if animated objs have
// been specified in args.
void PopulateShapesOrAnimShapes(
                    const ArgOptions &args,
                    std::vector<ShapeDesc> *defaultShapes, 
                    const ObjAnim **objAnim);


} // namespace ViewerArgsUtils

#endif // VIEWER_ARGS_UTILS_H
