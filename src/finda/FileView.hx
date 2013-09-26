package finda;
import java.awt.Color;
import java.awt.Shape;
import java.awt.geom.Rectangle2D;
import java.awt.geom.GeneralPath;

typedef FileView =
{
    file: FileSpec,
    shape: Shape,
    generalPath: GeneralPath,
    change: Bool,
    color: Color,
    x: Float,
    y: Float,
    width: Int,
    height: Int
}