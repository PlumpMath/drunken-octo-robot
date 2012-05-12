/*
 * world.h
 *
 *  Created on: 2012-05-08
 *      Author: dri
 *
 * This is a python to C++ translation of Panda3d 1.7 sample/tutorial:
 * Tut-Looking-and-Gripping.py
 *
 */

#ifndef WORLD_H_
#define WORLD_H_

#include "windowFramework.h"

class World
   {
   public:

   World(WindowFramework* windowFrameworkPtr);

   private:

   enum Alignment
      {
      A_center = TextNode::A_center,
      A_left   = TextNode::A_left
      };

   enum Model
      {
      M_teapot = 0,
      M_candy_cane,
      M_banana,
      M_sword,
      M_models
      };

   struct ModelData
      {
      string m_filename;
      LVecBase3f m_pos;
      LVecBase3f m_hpr;
      float m_scale;
      ModelData();
      ModelData(const string& filename, const LVecBase3f& pos, const LVecBase3f& hpr, float scale);
      };

   World(); // to prevent use of default constructor
   NodePath onscreen_text(const string& text, const Colorf& fg, const LPoint2f& pos, Alignment align, float scale);
   NodePath gen_label_text(const string& text, int i);
   void set_object(int i);
   static void sys_exit(const Event* eventPtr, void* dataPtr);
   static void set_teapot(const Event* eventPtr, void* dataPtr);
   static void set_candy_cane(const Event* eventPtr, void* dataPtr);
   static void set_banana(const Event* eventPtr, void* dataPtr);
   static void set_sword(const Event* eventPtr, void* dataPtr);
   static AsyncTask::DoneStatus turn_head(GenericAsyncTask* taskPtr, void* dataPtr);
   static float restrain(float i, float mn = -1, float mx = 1);
   void setup_lights();

   PT(WindowFramework) m_windowFrameworkPtr;
   AnimControlCollection m_animControlCollection;
   NodePath m_titleNp;
   NodePath m_esckeyTextNp;
   NodePath m_onekeyTextNp;
   NodePath m_twokeyTextNp;
   NodePath m_threekeyTextNp;
   NodePath m_fourkeyTextNp;
   NodePath m_eveNp;
   NodePath m_eveNeckNp;
   NodePath m_eveRightHandNp;
   vector<NodePath> m_modelsNp;
   };

inline
World::ModelData::ModelData()
   : m_scale(0)
   {
   // Empty
   }

inline
World::ModelData::ModelData(const string& filename, const LVecBase3f& pos, const LVecBase3f& hpr, float scale)
   : m_filename(filename),
     m_pos(pos),
     m_hpr(hpr),
     m_scale(scale)
   {
   // empty
   }

#endif /* WORLD_H_ */