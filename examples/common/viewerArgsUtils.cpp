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

#include "../common/viewerArgsUtils.h"

#include "../common/objAnim.h"
#include "../common/shapeDesc.h"

#include <fstream>
#include <sstream>

namespace ViewerArgsUtils {

const ObjAnim *
PopulateAnimShapes(const ArgOptions &args, 
                   std::vector<ShapeDesc> *defaultShapes)
{
    if (!defaultShapes)
        return NULL;

    if (args.GetObjFiles().empty())
        return NULL;


    const ObjAnim *objAnim = ObjAnim::Create(args.GetObjFiles(), args.GetAxis(),
        args.GetDefaultScheme());

    if (objAnim) {
        defaultShapes->push_back(ShapeDesc(args.GetObjFiles()[0], "", 
            args.GetDefaultScheme()));
    }

    return objAnim;

}

void 
PopulateShapes(const ArgOptions &args,
               std::vector<ShapeDesc> *defaultShapes)
{
    if (!defaultShapes)
        return;

    if (args.GetObjFiles().empty())
        return;

    for (size_t i = 0; i < args.GetObjFiles().size(); ++i) {
        std::ifstream ifs(args.GetObjFiles()[i]);
        if (ifs) {
            std::stringstream ss;
            ss << ifs.rdbuf();
            ifs.close();
            std::string str = ss.str();
            defaultShapes->push_back(ShapeDesc(
                        args.GetObjFiles()[i], str.c_str(), 
                        args.GetDefaultScheme()));
        } else {
            printf("Warning: cannot open shape file '%s'\n", 
                   args.GetObjFiles()[i]);
        }
    }

}

void 
PopulateShapesOrAnimShapes(
    const ArgOptions &args, 
    std::vector<ShapeDesc> *defaultShapes, 
    const ObjAnim **objAnim)
{
    if (!defaultShapes)
        return;

    if (args.GetObjFiles().empty())
        return;

    if (args.GetObjsAreAnim()) {

        if (!objAnim) {
            printf("Warning: animations of objs are unsupported in this "
                   "viewer.\n");
            return;
        }

        *objAnim = PopulateAnimShapes(args, defaultShapes);

    } else {

        PopulateShapes(args, defaultShapes);

    }
}

}
