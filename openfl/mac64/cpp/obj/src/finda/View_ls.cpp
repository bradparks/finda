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
#ifndef INCLUDED_finda_PathInfo
#include <finda/PathInfo.h>
#endif
#ifndef INCLUDED_finda_View_ls
#include <finda/View_ls.h>
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
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_MouseEvent
#include <flash/events/MouseEvent.h>
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

Void View_ls_obj::__construct(::finda::PathInfo pathInfo_,int x_,int y_)
{
HX_STACK_PUSH("View_ls::new","finda/View_ls.hx",14);
{
	HX_STACK_LINE(17)
	this->y = (int)0;
	HX_STACK_LINE(16)
	this->x = (int)0;
	HX_STACK_LINE(24)
	this->x = x_;
	HX_STACK_LINE(25)
	this->y = y_;
	HX_STACK_LINE(26)
	this->pathInfo = pathInfo_;
	HX_STACK_LINE(27)
	this->change();
}
;
	return null();
}

View_ls_obj::~View_ls_obj() { }

Dynamic View_ls_obj::__CreateEmpty() { return  new View_ls_obj; }
hx::ObjectPtr< View_ls_obj > View_ls_obj::__new(::finda::PathInfo pathInfo_,int x_,int y_)
{  hx::ObjectPtr< View_ls_obj > result = new View_ls_obj();
	result->__construct(pathInfo_,x_,y_);
	return result;}

Dynamic View_ls_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< View_ls_obj > result = new View_ls_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Dynamic View_ls_obj::overCheck( ::flash::events::MouseEvent e){
	HX_STACK_PUSH("View_ls::overCheck","finda/View_ls.hx",79);
	HX_STACK_THIS(this);
	HX_STACK_ARG(e,"e");
	struct _Function_1_1{
		inline static Dynamic Block( ::flash::events::MouseEvent &e){
			HX_STACK_PUSH("*::closure","finda/View_ls.hx",83);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("x") , e->localX,false);
				__result->Add(HX_CSTRING("y") , e->localY,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(83)
	Dynamic point = _Function_1_1::Block(e);		HX_STACK_VAR(point,"point");
	HX_STACK_LINE(85)
	{
		HX_STACK_LINE(85)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Dynamic _g1 = this->shapes;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(85)
		while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(85)
			Dynamic fileView = _g1->__GetItem(_g);		HX_STACK_VAR(fileView,"fileView");
			HX_STACK_LINE(85)
			++(_g);
			HX_STACK_LINE(87)
			if (((bool((bool((bool((point->__Field(HX_CSTRING("x"),true) > fileView->__Field(HX_CSTRING("x"),true))) && bool((point->__Field(HX_CSTRING("x"),true) < (fileView->__Field(HX_CSTRING("x"),true) + fileView->__Field(HX_CSTRING("width"),true)))))) && bool((point->__Field(HX_CSTRING("y"),true) > fileView->__Field(HX_CSTRING("y"),true))))) && bool((point->__Field(HX_CSTRING("y"),true) < (fileView->__Field(HX_CSTRING("y"),true) + fileView->__Field(HX_CSTRING("height"),true))))))){
				HX_STACK_LINE(92)
				return fileView;
			}
		}
	}
	HX_STACK_LINE(96)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(View_ls_obj,overCheck,return )

Void View_ls_obj::clicked( Dynamic f){
{
		HX_STACK_PUSH("View_ls::clicked","finda/View_ls.hx",66);
		HX_STACK_THIS(this);
		HX_STACK_ARG(f,"f");
		HX_STACK_LINE(66)
		if ((f->__Field(HX_CSTRING("file"),true)->__Field(HX_CSTRING("isDir"),true))){
			HX_STACK_LINE(67)
			if (((f->__Field(HX_CSTRING("file"),true)->__Field(HX_CSTRING("name"),true) == HX_CSTRING("<-")))){
				HX_STACK_LINE(69)
				this->pathInfo->changePath(this->pathInfo->parent);
				HX_STACK_LINE(70)
				this->change();
			}
			else{
				HX_STACK_LINE(72)
				this->pathInfo->changePath((((this->pathInfo->full + HX_CSTRING("/")) + f->__Field(HX_CSTRING("file"),true)->__Field(HX_CSTRING("name"),true)) + HX_CSTRING("/")));
				HX_STACK_LINE(73)
				this->change();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(View_ls_obj,clicked,(void))

Void View_ls_obj::secondPaint( ::flash::display::Sprite g2D){
{
		HX_STACK_PUSH("View_ls::secondPaint","finda/View_ls.hx",44);
		HX_STACK_THIS(this);
		HX_STACK_ARG(g2D,"g2D");
		HX_STACK_LINE(45)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Dynamic _g1 = this->shapes;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(45)
		while(((_g < _g1->__Field(HX_CSTRING("length"),true)))){
			HX_STACK_LINE(45)
			Dynamic fileView = _g1->__GetItem(_g);		HX_STACK_VAR(fileView,"fileView");
			HX_STACK_LINE(45)
			++(_g);
			HX_STACK_LINE(59)
			fileView->__Field(HX_CSTRING("shape"),true)->__Field(HX_CSTRING("set_x"),true)(fileView->__Field(HX_CSTRING("x"),true));
			HX_STACK_LINE(60)
			fileView->__Field(HX_CSTRING("shape"),true)->__Field(HX_CSTRING("set_y"),true)(fileView->__Field(HX_CSTRING("y"),true));
			HX_STACK_LINE(61)
			g2D->addChild(fileView->__Field(HX_CSTRING("shape"),true));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(View_ls_obj,secondPaint,(void))

Void View_ls_obj::firstPaint( ::flash::display::Sprite g2D){
{
		HX_STACK_PUSH("View_ls::firstPaint","finda/View_ls.hx",37);
		HX_STACK_THIS(this);
		HX_STACK_ARG(g2D,"g2D");
		struct _Function_1_1{
			inline static Dynamic Block( ::finda::View_ls_obj *__this,::flash::display::Sprite &g2D){
				HX_STACK_PUSH("*::closure","finda/View_ls.hx",38);
				{
					HX_STACK_LINE(38)
					::String p = __this->pathInfo->path;		HX_STACK_VAR(p,"p");
					HX_STACK_LINE(38)
					Dynamic isDir = ::sys::FileSystem_obj::isDirectory_dyn();		HX_STACK_VAR(isDir,"isDir");
					HX_STACK_LINE(38)
					Dynamic stat = ::sys::FileSystem_obj::stat_dyn();		HX_STACK_VAR(stat,"stat");
					HX_STACK_LINE(38)
					Dynamic charcode = ::StringTools_obj::fastCodeAt_dyn();		HX_STACK_VAR(charcode,"charcode");
					HX_STACK_LINE(38)
					Array< ::String > ls = ::sys::FileSystem_obj::readDirectory(p);		HX_STACK_VAR(ls,"ls");
					HX_STACK_LINE(38)
					::finda::FileViewCreatorFL fileViewCreator = ::finda::FileViewCreatorFL_obj::__new(g2D,__this->x);		HX_STACK_VAR(fileViewCreator,"fileViewCreator");
					HX_STACK_LINE(38)
					Dynamic shapes = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(shapes,"shapes");
					HX_STACK_LINE(38)
					Dynamic folder = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(folder,"folder");
					struct _Function_2_1{
						inline static Dynamic Block( ){
							HX_STACK_PUSH("*::closure","finda/View_ls.hx",38);
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
					HX_STACK_LINE(38)
					folder->__Field(HX_CSTRING("push"),true)(_Function_2_1::Block());
					HX_STACK_LINE(38)
					{
						HX_STACK_LINE(38)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(38)
						while(((_g < ls->length))){
							HX_STACK_LINE(38)
							::String f = ls->__get(_g);		HX_STACK_VAR(f,"f");
							HX_STACK_LINE(38)
							++(_g);
							HX_STACK_LINE(38)
							::String pf = (p + f);		HX_STACK_VAR(pf,"pf");
							HX_STACK_LINE(38)
							bool hasDir = isDir(pf).Cast< bool >();		HX_STACK_VAR(hasDir,"hasDir");
							HX_STACK_LINE(38)
							if (((f.substr((int)0,(int)1) == HX_CSTRING(".")))){
								HX_STACK_LINE(38)
								hasDir = false;
							}
							struct _Function_4_1{
								inline static int Block( ::String &p,::String &f){
									HX_STACK_PUSH("*::closure","finda/View_ls.hx",38);
									{
										HX_STACK_LINE(38)
										Array< ::String > ls2 = ::sys::FileSystem_obj::readDirectory(((p + HX_CSTRING("/")) + f));		HX_STACK_VAR(ls2,"ls2");
										HX_STACK_LINE(38)
										return ls2->length;
									}
									return null();
								}
							};
							HX_STACK_LINE(38)
							int len = (  ((hasDir)) ? int(_Function_4_1::Block(p,f)) : int((int)0) );		HX_STACK_VAR(len,"len");
							struct _Function_4_2{
								inline static Dynamic Block( int &len,::String &pf,bool &hasDir,Dynamic &charcode,::String &f,Dynamic &stat){
									HX_STACK_PUSH("*::closure","finda/View_ls.hx",38);
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
							HX_STACK_LINE(38)
							folder->__Field(HX_CSTRING("push"),true)(_Function_4_2::Block(len,pf,hasDir,charcode,f,stat));
						}
					}

					HX_BEGIN_LOCAL_FUNC_S0(hx::LocalFunc,_Function_2_2)
					int run(Dynamic f1,Dynamic f2){
						HX_STACK_PUSH("*::_Function_2_2","finda/View_ls.hx",38);
						HX_STACK_ARG(f1,"f1");
						HX_STACK_ARG(f2,"f2");
						{
							HX_STACK_LINE(38)
							if (((bool(f1->__Field(HX_CSTRING("isDir"),true)) && bool(!(f2->__Field(HX_CSTRING("isDir"),true)))))){
								HX_STACK_LINE(38)
								return (int)-1;
							}
							HX_STACK_LINE(38)
							if (((bool(!(f1->__Field(HX_CSTRING("isDir"),true))) && bool(f2->__Field(HX_CSTRING("isDir"),true))))){
								HX_STACK_LINE(38)
								return (int)1;
							}
							HX_STACK_LINE(38)
							if (((f1->__Field(HX_CSTRING("firstLetter"),true) > f2->__Field(HX_CSTRING("firstLetter"),true)))){
								HX_STACK_LINE(38)
								return (int)1;
							}
							HX_STACK_LINE(38)
							if (((f1->__Field(HX_CSTRING("firstLetter"),true) < f2->__Field(HX_CSTRING("firstLetter"),true)))){
								HX_STACK_LINE(38)
								return (int)-1;
							}
							HX_STACK_LINE(38)
							return (int)0;
						}
						return null();
					}
					HX_END_LOCAL_FUNC2(return)

					HX_STACK_LINE(38)
					folder->__Field(HX_CSTRING("sort"),true)( Dynamic(new _Function_2_2()));
					HX_STACK_LINE(38)
					int h = __this->y;		HX_STACK_VAR(h,"h");
					HX_STACK_LINE(38)
					{
						HX_STACK_LINE(38)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(38)
						while(((_g < folder->__Field(HX_CSTRING("length"),true)))){
							HX_STACK_LINE(38)
							Dynamic file = folder->__GetItem(_g);		HX_STACK_VAR(file,"file");
							HX_STACK_LINE(38)
							++(_g);
							HX_STACK_LINE(38)
							::String tx = file->__Field(HX_CSTRING("name"),true);		HX_STACK_VAR(tx,"tx");
							HX_STACK_LINE(38)
							int c;		HX_STACK_VAR(c,"c");
							HX_STACK_LINE(38)
							if (((file->__Field(HX_CSTRING("fileStat"),true) != null()))){
								HX_STACK_LINE(38)
								hx::AddEq(tx,(HX_CSTRING("   ") + file->__Field(HX_CSTRING("fileStat"),true)->__Field(HX_CSTRING("size"),true)));
								HX_STACK_LINE(38)
								c = (  ((file->__Field(HX_CSTRING("isDir"),true))) ? int((int)0) : int((int)255) );
								HX_STACK_LINE(38)
								if ((file->__Field(HX_CSTRING("isDir"),true))){
									HX_STACK_LINE(38)
									hx::AddEq(tx,((HX_CSTRING(" [") + file->__Field(HX_CSTRING("subDirLen"),true)) + HX_CSTRING("]")));
								}
							}
							else{
								HX_STACK_LINE(38)
								c = (int)16711680;
							}
							struct _Function_4_1{
								inline static Dynamic Block( int &c,::finda::FileViewCreatorFL &fileViewCreator,Dynamic &file,int &h,::String &tx){
									HX_STACK_PUSH("*::closure","finda/View_ls.hx",38);
									{
										HX_STACK_LINE(38)
										int h1 = h;		HX_STACK_VAR(h1,"h1");
										HX_STACK_LINE(38)
										::flash::display::Bitmap shape = fileViewCreator->bitmapTextCreator->getBitmap(tx);		HX_STACK_VAR(shape,"shape");
										HX_STACK_LINE(38)
										int wide = ::Std_obj::_int(shape->get_width());		HX_STACK_VAR(wide,"wide");
										HX_STACK_LINE(38)
										int hi = ::Std_obj::_int(shape->get_height());		HX_STACK_VAR(hi,"hi");
										HX_STACK_LINE(38)
										int xpos = fileViewCreator->x;		HX_STACK_VAR(xpos,"xpos");
										HX_STACK_LINE(38)
										int ypos = hx::AddEq(h1,hi);		HX_STACK_VAR(ypos,"ypos");
										HX_STACK_LINE(38)
										{
											HX_STACK_LINE(38)
											int red = (int(c) >> int((int)16));		HX_STACK_VAR(red,"red");
											HX_STACK_LINE(38)
											int green = (int((int(c) >> int((int)8))) & int((int)255));		HX_STACK_VAR(green,"green");
											HX_STACK_LINE(38)
											int blue = (int(c) & int((int)255));		HX_STACK_VAR(blue,"blue");
											HX_STACK_LINE(38)
											shape->get_transform()->set_colorTransform(::flash::geom::ColorTransform_obj::__new((int)0,(int)0,(int)0,(int)1,red,green,blue,(int)0));
										}
										struct _Function_5_1{
											inline static Dynamic Block( int &c,int &wide,::flash::display::Bitmap &shape,int &hi,int &xpos,Dynamic &file,int &ypos){
												HX_STACK_PUSH("*::closure","finda/View_ls.hx",38);
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
										HX_STACK_LINE(38)
										Dynamic fileView = _Function_5_1::Block(c,wide,shape,hi,xpos,file,ypos);		HX_STACK_VAR(fileView,"fileView");
										HX_STACK_LINE(38)
										return fileView;
									}
									return null();
								}
							};
							HX_STACK_LINE(38)
							Dynamic fileView = _Function_4_1::Block(c,fileViewCreator,file,h,tx);		HX_STACK_VAR(fileView,"fileView");
							HX_STACK_LINE(38)
							h = fileView->__Field(HX_CSTRING("y"),true);
							HX_STACK_LINE(38)
							shapes->__Field(HX_CSTRING("push"),true)(fileView);
						}
					}
					HX_STACK_LINE(38)
					return shapes;
				}
				return null();
			}
		};
		HX_STACK_LINE(38)
		this->shapes = _Function_1_1::Block(this,g2D);
		HX_STACK_LINE(39)
		this->repaint = this->secondPaint_dyn();
		HX_STACK_LINE(40)
		this->repaint(g2D);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(View_ls_obj,firstPaint,(void))

Void View_ls_obj::change( ){
{
		HX_STACK_PUSH("View_ls::change","finda/View_ls.hx",31);
		HX_STACK_THIS(this);
		HX_STACK_LINE(31)
		this->repaint = this->firstPaint_dyn();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(View_ls_obj,change,(void))


View_ls_obj::View_ls_obj()
{
}

void View_ls_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(View_ls);
	HX_MARK_MEMBER_NAME(shapes,"shapes");
	HX_MARK_MEMBER_NAME(repaint,"repaint");
	HX_MARK_MEMBER_NAME(pathInfo,"pathInfo");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_END_CLASS();
}

void View_ls_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(shapes,"shapes");
	HX_VISIT_MEMBER_NAME(repaint,"repaint");
	HX_VISIT_MEMBER_NAME(pathInfo,"pathInfo");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
}

Dynamic View_ls_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"change") ) { return change_dyn(); }
		if (HX_FIELD_EQ(inName,"shapes") ) { return shapes; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"clicked") ) { return clicked_dyn(); }
		if (HX_FIELD_EQ(inName,"repaint") ) { return repaint; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"pathInfo") ) { return pathInfo; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"overCheck") ) { return overCheck_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"firstPaint") ) { return firstPaint_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"secondPaint") ) { return secondPaint_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic View_ls_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shapes") ) { shapes=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"repaint") ) { repaint=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"pathInfo") ) { pathInfo=inValue.Cast< ::finda::PathInfo >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void View_ls_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("shapes"));
	outFields->push(HX_CSTRING("pathInfo"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("overCheck"),
	HX_CSTRING("clicked"),
	HX_CSTRING("secondPaint"),
	HX_CSTRING("firstPaint"),
	HX_CSTRING("change"),
	HX_CSTRING("shapes"),
	HX_CSTRING("repaint"),
	HX_CSTRING("pathInfo"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(View_ls_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(View_ls_obj::__mClass,"__mClass");
};

Class View_ls_obj::__mClass;

void View_ls_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("finda.View_ls"), hx::TCanCast< View_ls_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void View_ls_obj::__boot()
{
}

} // end namespace finda
