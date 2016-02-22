#ifndef SHADER
#define SHADER

//QT Headers
#include <QtOpenGL/QGL>
#include <QVector>
#include <QString>

//User Defined Headers
#include "MathTypes.h"

//User Defines
#define filePath ".csm"
#define MaxSources 5

namespace clim{
namespace graphics{


    enum class SHADER_TYPE { VERTEX=0 ,FRAGMENT=1,GEOMETRY=2, TESSALATION1=3,TESSALATION2=4};

    /*SHADER TYPES:
     *
     * Vertex Shaders:
     *     Vertex shaders are the most established and common kind of 3d shader and are run once for each
     * vertex given to the graphics processor. The purpose is to transform each vertex's 3D position in virtual
     * space to the 2D coordinate at which it appears on the screen (as well as a depth value for the Z-buffer).
     * Vertex shaders can manipulate properties such as position, color and texture coordinate, but cannot create
     * new vertices. The output of the vertex shader goes to the next stage in the pipeline, which is either a geometry
     * shader if present, or the rasterizer. Vertex shaders can enable powerful control over the details of position, movement,
     * lighting, and color in any scene involving 3D models.
     *
     * Fragment Shaders :
     *      Pixel shaders, also known as fragment shaders, compute color and other attributes of each "fragment" -
     * a technical term usually meaning a single pixel. The simplest kinds of pixel shaders output one screen pixel
     * as a color value; more complex shaders with multiple inputs/outputs are also possible. Pixel shaders range
     * from always outputting the same color, to applying a lighting value, to doing bump mapping, shadows, specular
     * highlights, translucency and other phenomena. They can alter the depth of the fragment (for Z-buffering), or
     * output more than one color if multiple render targets are active. In 3D graphics, a pixel shader alone cannot
     * produce very complex effects, because it operates only on a single fragment, without knowledge of a scene's geometry.
     * However, pixel shaders do have knowledge of the screen coordinate being drawn, and can sample the screen and nearby
     * pixels if the contents of the entire screen are passed as a texture to the shader. This technique can enable a wide
     * variety of two-dimensional postprocessing effects, such as blur, or edge detection/enhancement for cartoon/cel shaders.
     * Pixel shaders may also be applied in intermediate stages to any two-dimensional images—sprites or textures—in the pipeline,
     * whereas vertex shaders always require a 3D scene. For instance, a pixel shader is the only kind of shader that can act as a
     * postprocessor or filter for a video stream after it has been rasterized.
     *
     * Geometry shaders:
     *      Geometry shader programs are executed after vertex shaders. They take as input a whole primitive,
     * possibly with adjacency information. For example, when operating on triangles, the three vertices
     * are the geometry shader's input. The shader can then emit zero or more primitives, which are rasterized
     * and their fragments ultimately passed to a pixel shader.
     *
     *      Typical uses of a geometry shader include point sprite generation, geometry tessellation, shadow volume
     * extrusion, and single pass rendering to a cube map. A typical real world example of the benefits of geometry
     * shaders would be automatic mesh complexity modification. A series of line strips representing control points
     * for a curve are passed to the geometry shader and depending on the complexity required the shader can automatically
     * generate extra lines each of which provides a better approximation of a curve.
     *
     *
     * Tessalation shaders:
     *       Tessellation control shaders (also known as hull shaders) and tessellation evaluation shaders (also known as
     * Domain Shaders), which together allow for simpler meshes to be subdivided into finer meshes at run-time according
     * to a mathematical function. The function can be related to a variety of variables, most notably the distance from
     * the viewing camera to allow active level-of-detail scaling. This allows objects close to the camera to have fine
     * detail, while further away ones can have more coarse meshes, yet seem comparable in quality. It also can drastically
     * reduce mesh bandwidth by allowing meshes to be refined once inside the shader units instead of downsampling very complex
     * ones from memory. Some algorithms can upsample any arbitrary mesh, while others allow for "hinting" in meshes to
     * dictate the most characteristic vertices and edges.
     *
     */

    /*SHADER USAGE:
     * Shader will be created, then shader sources will be added in, the order will be : VERTEX, GEOMETRY, FRAGMENT, TESSALATION
     *
     * The user can eather Create one, and then add the sources, and load manually, or call a shader constructor with Vertex and Fragment shader
     * sources that load on creation.
     *
     *
     */

    class Shader{


    private:
        QString m_name;
        QString m_filepath;
        QVector<QString> m_sources;
        QVector<QString> m_sourceFilePath;
        quint32 m_ShaderID;

        quint32 load(const char* vertSrc, const char* fragSrc) const;
        int getUniformLocation(const GLchar* name) const;

    public:
        Shader(const QString& name);
        Shader(const QString& name, const QString *vertSource, const QString *fragSource );
        ~Shader();


        void addSource(const QString& source);
        void setUniform1f(const QString& name, float value);
        void setUniform1fv(const QString& name, float* value, int count);
        void setUniform1i(const QString& name, int value);
        void setUniform1iv(const QString& name, int* value, int count);
        void setUniform2f(const QString& name, const math::vec2<float>& vector);
        void setUniform3f(const QString& name, const math::vec3<float>& vector);
        void setUniform4f(const QString& name, const math::vec4<float>& vector);
        void setUniformMat4(const QString& name, const math::mat4<float>& matrix);

        void setUniform(const QString& name, byte* data);
        void resolveAndSetUniform(uint index, byte* data);
        void resolveAndSetUniforms(byte* data, uint size);

        void bind() const;
        void unbind() const;

        bool hasUniform(const QString& name) const;


        static Shader* FromFile(const char* vertPath, const char* fragPath);
        static Shader* FromSource(const char* vertSrc, const char* fragSrc);
        static Shader* FromSource(const char* name, const char* vertSrc, const char* fragSrc);
    };

}
}
#endif // SHADER

