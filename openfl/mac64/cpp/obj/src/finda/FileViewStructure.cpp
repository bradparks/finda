#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_finda_BitmapTextCreator
#include <finda/BitmapTextCreator.h>
#endif
#ifndef INCLUDED_finda_FileViewCreatorFL
#include <finda/FileViewCreatorFL.h>
#endif
#ifndef INCLUDED_finda_FileViewStructure
#include <finda/FileViewStructure.h>
#endif
#ifndef INCLUDED_flash_display_Bitmap
#include <flash/display/Bitmap.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_geom_ColorTransform
#include <flash/geom/ColorTransform.h>
#endif
#ifndef INCLUDED_flash_geom_Transform
#include <flash/geom/Transform.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
namespace finda{

Void FileViewStructure_obj::__construct()
{
	return null();
}

FileViewStructure_obj::~FileViewStructure_obj() { }

Dynamic FileViewStructure_obj::__CreateEmpty() { return  new FileViewStructure_obj; }
hx::ObjectPtr< FileViewStructure_obj > FileViewStructure_obj::__new()
{  hx::ObjectPtr< FileViewStructure_obj > result = new FileViewStructure_obj();
	result->__construct();
	return result;}

Dynamic FileViewStructure_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileViewStructure_obj > result = new FileViewStructure_obj();
	result->__construct();
	return result;}

Dynamic FileViewStructure_obj::construct( ::flash::display::Sprite g2D,::String path,int x,int y){
	HX_STACK_PUSH("FileViewStructure::construct","finda/FileViewStructure.hx",17);
	HX_STACK_ARG(g2D,"g2D");
	HX_STACK_ARG(path,"path");
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(18)
	::String p = path;		HX_STACK_VAR(p,"p");
	HX_STACK_LINE(19)
	Dynamic isDir = ::sys::FileSystem_obj::isDirectory_dyn();		HX_STACK_VAR(isDir,"isDir");
	HX_STACK_LINE(20)
	Dynamic stat = ::sys::FileSystem_obj::stat_dyn();		HX_STACK_VAR(stat,"stat");
	HX_STACK_LINE(21)
	Dynamic charcode = ::StringTools_obj::fastCodeAt_dyn();		HX_STACK_VAR(charcode,"charcode");
	HX_STACK_LINE(22)
	Array< ::String > ls = ::sys::FileSystem_obj::readDirectory(p);		HX_STACK_VAR(ls,"ls");
	HX_STACK_LINE(26)
	::finda::FileViewCreatorFL fileViewCreator = ::finda::FileViewCreatorFL_obj::__new(g2D,x);		HX_STACK_VAR(fileViewCreator,"fileViewCreator");
	HX_STACK_LINE(28)
	Dynamic shapes = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(shapes,"shapes");
	HX_STACK_LINE(29)
	Dynamic folder = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(folder,"folder");
	struct _Function_1_1{
		inline static Dynamic Block( ){
			HX_STACK_PUSH("*::closure","finda/FileViewStructure.hx",30);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("name") , HX_CSTRING("<-"),false);
				__result->Add(HX_CSTRING("isDir") , true,false);
				__result->Add(HX_CSTRING("firstLetter") , (int)0,false);
				__result->Add(HX_CSTRING("fileStat") , null(),false);
				__result->Add(HX_CSTRING("subDirLen") , (int)0,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(30)
	folder->__Field(HX_CSTRING("push"),true)(_Function_1_1::Block());
	HX_STACK_LINE(32)
	{
		HX_STACK_LINE(32)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(32)
		while(((_g < ls->length))){
			HX_STACK_LINE(32)
			::String f = ls->__get(_g);		HX_STACK_VAR(f,"f");
			HX_STACK_LINE(32)
			++(_g);
			HX_STACK_LINE(34)
			::String pf = (p + f);		HX_STACK_VAR(pf,"pf");
			HX_STACK_LINE(35)
			bool hasDir = isDir(pf).Cast< bool >();		HX_STACK_VAR(hasDir,"hasDir");
			HX_STACK_LINE(36)
			if (((f.substr((int)0,(int)1) == HX_CSTRING(".")))){
				HX_STACK_LINE(36)
				hasDir = false;
			}
			struct _Function_3_1{
				inline static int Block( ::String &p,::String &f){
					HX_STACK_PUSH("*::closure","finda/FileViewStructure.hx",38);
					{
						HX_STACK_LINE(39)
						Array< ::String > ls2 = ::sys::FileSystem_obj::readDirectory(((p + HX_CSTRING("/")) + f));		HX_STACK_VAR(ls2,"ls2");
						HX_STACK_LINE(40)
						return ls2->length;
					}
					return null();
				}
			};
			HX_STACK_LINE(37)
			int len = (  ((hasDir)) ? int(_Function_3_1::Block(p,f)) : int((int)0) );		HX_STACK_VAR(len,"len");
			struct _Function_3_2{
				inline static Dynamic Block( int &len,::String &pf,bool &hasDir,Dynamic &charcode,::String &f,Dynamic &stat){
					HX_STACK_PUSH("*::closure","finda/FileViewStructure.hx",45);
					{
						hx::Anon __result = hx::Anon_obj::Create();
						__result->Add(HX_CSTRING("name") , f,false);
						__result->Add(HX_CSTRING("isDir") , hasDir,false);
						__result->Add(HX_CSTRING("firstLetter") , charcode(f,(int)0).Cast< int >(),false);
						__result->Add(HX_CSTRING("fileStat") , stat(pf),false);
						__result->Add(HX_CSTRING("subDirLen") , len,false);
						return __result;
					}
					return null();
				}
			};
			HX_STACK_LINE(45)
			folder->__Field(HX_CSTRING("push"),true)(_Function_3_2::Block(len,pf,hasDir,charcode,f,stat));
		}
	}

	HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_1_2)
	int run(Dynamic f1,Dynamic f2){
		HX_STACK_PUSH("*::_Function_1_2","finda/FileViewStructure.hx",55);
		HX_STACK_ARG(f1,"f1");
		HX_STACK_ARG(f2,"f2");
		{
			HX_STACK_LINE(56)
			if (((bool(f1->__Field(HX_CSTRING("isDir"),true)) && bool(!(f2->__Field(HX_CSTRING("isDir"),true)))))){
				HX_STACK_LINE(56)
				return (int)-1;
			}
			HX_STACK_LINE(57)
			if (((bool(!(f1->__Field(HX_CSTRING("isDir"),true))) && bool(f2->__Field(HX_CSTRING("isDir"),true))))){
				HX_STACK_LINE(57)
				return (int)1;
			}
			HX_STACK_LINE(58)
			if (((f1->__Field(HX_CSTRING("firstLetter"),true) > f2->__Field(HX_CSTRING("firstLetter"),true)))){
				HX_STACK_LINE(58)
				return (int)1;
			}
			HX_STACK_LINE(59)
			if (((f1->__Field(HX_CSTRING("firstLetter"),true) < f2->__Field(HX_CSTRING("firstLetter"),true)))){
				HX_STACK_LINE(59)
				return (int)-1;
			}
			HX_STACK_LINE(60)
			return (int)0;
		}
		return null();
	}
	HX_END_LOCAL_FUNC2(return)

	HX_STACK_LINE(53)
	folder->__Field(HX_CSTRING("sort"),true)( Dynamic(new _Function_1_2()));
	HX_STACK_LINE(64)
	int h = y;		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(65)
	{
		HX_STACK_LINE(65)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(65)
		while(((_g < folder->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(65)
			Dynamic file = folder->__GetItem(_g);		HX_STACK_VAR(file,"file");
			HX_STACK_LINE(65)
			++(_g);
			HX_STACK_LINE(67)
			::String tx = file->__Field(HX_CSTRING("name"),true);		HX_STACK_VAR(tx,"tx");
			HX_STACK_LINE(68)
			int c;		HX_STACK_VAR(c,"c");
			HX_STACK_LINE(69)
			if (((file->__Field(HX_CSTRING("fileStat"),true) != null()))){
				HX_STACK_LINE(71)
				hx::AddEq(tx,(HX_CSTRING("   ") + file->__Field(HX_CSTRING("fileStat"),true)->__Field(HX_CSTRING("size"),true)));
				HX_STACK_LINE(72)
				c = (  ((file->__Field(HX_CSTRING("isDir"),true))) ? int((int)0) : int((int)255) );
				HX_STACK_LINE(73)
				if ((file->__Field(HX_CSTRING("isDir"),true))){
					HX_STACK_LINE(74)
					hx::AddEq(tx,((HX_CSTRING(" [") + file->__Field(HX_CSTRING("subDirLen"),true)) + HX_CSTRING("]")));
				}
			}
			else{
				HX_STACK_LINE(78)
				c = (int)16711680;
			}
			struct _Function_3_1{
				inline static Dynamic Block( int &c,::finda::FileViewCreatorFL &fileViewCreator,Dynamic &file,int &h,::String &tx){
					HX_STACK_PUSH("*::closure","finda/FileViewStructure.hx",86);
					{
						HX_STACK_LINE(86)
						int h1 = h;		HX_STACK_VAR(h1,"h1");
						HX_STACK_LINE(86)
						::flash::display::Bitmap shape = fileViewCreator->bitmapTextCreator->getBitmap(tx);		HX_STACK_VAR(shape,"shape");
						HX_STACK_LINE(86)
						int wide = ::Std_obj::_int(shape->get_width());		HX_STACK_VAR(wide,"wide");
						HX_STACK_LINE(86)
						int hi = ::Std_obj::_int(shape->get_height());		HX_STACK_VAR(hi,"hi");
						HX_STACK_LINE(86)
						int xpos = fileViewCreator->x;		HX_STACK_VAR(xpos,"xpos");
						HX_STACK_LINE(86)
						int ypos = hx::AddEq(h1,hi);		HX_STACK_VAR(ypos,"ypos");
						HX_STACK_LINE(86)
						{
							HX_STACK_LINE(86)
							int red = (int(c) >> int((int)16));		HX_STACK_VAR(red,"red");
							HX_STACK_LINE(86)
							int green = (int((int(c) >> int((int)8))) & int((int)255));		HX_STACK_VAR(green,"green");
							HX_STACK_LINE(86)
							int blue = (int(c) & int((int)255));		HX_STACK_VAR(blue,"blue");
							HX_STACK_LINE(86)
							shape->get_transform()->set_colorTransform(::flash::geom::ColorTransform_obj::__new((int)0,(int)0,(int)0,(int)1,red,green,blue,(int)0));
						}
						struct _Function_4_1{
							inline static Dynamic Block( int &c,int &wide,::flash::display::Bitmap &shape,int &hi,int &xpos,Dynamic &file,int &ypos){
								HX_STACK_PUSH("*::closure","finda/FileViewStructure.hx",86);
								{
									hx::Anon __result = hx::Anon_obj::Create();
									__result->Add(HX_CSTRING("file") , file,false);
									__result->Add(HX_CSTRING("shape") , shape,false);
									__result->Add(HX_CSTRING("change") , false,false);
									__result->Add(HX_CSTRING("color") , c,false);
									__result->Add(HX_CSTRING("x") , xpos,false);
									__result->Add(HX_CSTRING("y") , ypos,false);
									__result->Add(HX_CSTRING("width") , wide,false);
									__result->Add(HX_CSTRING("height") , hi,false);
									return __result;
								}
								return null();
							}
						};
						HX_STACK_LINE(86)
						Dynamic fileView = _Function_4_1::Block(c,wide,shape,hi,xpos,file,ypos);		HX_STACK_VAR(fileView,"fileView");
						HX_STACK_LINE(86)
						return fileView;
					}
					return null();
				}
			};
			HX_STACK_LINE(86)
			Dynamic fileView = _Function_3_1::Block(c,fileViewCreator,file,h,tx);		HX_STACK_VAR(fileView,"fileView");
			HX_STACK_LINE(87)
			h = fileView->__Field(HX_CSTRING("y"),true);
			HX_STACK_LINE(88)
			shapes->__Field(HX_CSTRING("push"),true)(fileView);
		}
	}
	HX_STACK_LINE(92)
	return shapes;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(FileViewStructure_obj,construct,return )


FileViewStructure_obj::FileViewStructure_obj()
{
}

void FileViewStructure_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FileViewStructure);
	HX_MARK_END_CLASS();
}

void FileViewStructure_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic FileViewStructure_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"construct") ) { return construct_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FileViewStructure_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void FileViewStructure_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("construct"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileViewStructure_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FileViewStructure_obj::__mClass,"__mClass");
};

Class FileViewStructure_obj::__mClass;

void FileViewStructure_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("finda.FileViewStructure"), hx::TCanCast< FileViewStructure_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FileViewStructure_obj::__boot()
{
}

} // end namespace finda
