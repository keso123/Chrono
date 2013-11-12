/*
        Copyright 2013 Luis Valero Martin

        This file is part of Chrono.

        Chrono is free software: you can redistribute it and/or modify
        it under the terms of the GNU General Public License as published by
        the Free Software Foundation, either version 3 of the License, or
        any later version.

        SubEditor is distributed in the hope that it will be useful,
        but WITHOUT ANY WARRANTY; without even the implied warranty of
        MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
        GNU General Public License for more details.

        You should have received a copy of the GNU General Public License
        along with SubEditor.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <Windows.h>
#include "ChronoClass.h"

namespace Chrono {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

		delegate void SetTextDelegate(String^ text);// delegate to enable asunchronous calls for setting the text
	
	private: Thread^ chronoThread;

	/*private: void setText(Object^ sender, EventArgs^ e){
				 this->chronoThread = gcnew Thread(gcnew ThreadStart(this,&MyForm::runThread));
				 this->chronoThread->Start;
			 }*/
	/*
	private: int hours;
	private: int minutes;
	private: int seconds;
	private: int ms;

	private: static int overH  = 100;
	private: static int overM  = 60;
	private: static int overS  = 60;
	private: static int overMS = 1000;
	*/
	private: ChronoClass^ chronoC;
	private: bool run;
	private: bool endChrono;

	private: void runThread(){

				 while(!endChrono){
					while(run){
						
						chronoC->increaseSleep();
						//chronoC->increaseSystem();
						this->setLabel(chronoC->toStringChrono());
					}
				 }
				 this->setLabel("00:00:00:000");
			 }

	private: void setLabel(String^ text){
				 if(this->label1->InvokeRequired){
					 SetTextDelegate^ d = gcnew SetTextDelegate(this, &MyForm::setLabel);
					 this->Invoke(d, gcnew array<Object^> {text});
				 }else{
					 label1->Text = text;
				 }
			 }

	public:
		MyForm(void)
		{
			InitializeComponent();
			
			chronoC = gcnew ChronoClass();

			run = false;
			endChrono = true;

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~MyForm()
		{
			
			if(endChrono == false) chronoThread->Abort();

			delete chronoC;

			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	protected: 

	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(27, 21);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(227, 66);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start/Pause";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(27, 179);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(227, 71);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Restart";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(19, 109);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(242, 44);
			this->label1->TabIndex = 3;
			this->label1->Text = L"00:00:00:000";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Chrono";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 //TODO: click start/pause
				 //label1->Text = "HOLA";

				 run = !run;
				 if(endChrono == true){
					 endChrono = false;
					 this->chronoThread = gcnew Thread(gcnew ThreadStart(this,&MyForm::runThread));
					 this->chronoThread->Start();
				 }
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 //label1->Text = "00:00:00:000";
				 run = false;
				 endChrono = true;
				 chronoC->restart();				
			 }
	};
}
