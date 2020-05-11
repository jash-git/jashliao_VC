#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Diagnostics;


namespace FormtestDLL {

	/// <summary>
	/// add 的摘要
	/// </summary>
	public ref class add :  public System::ComponentModel::Component
	{
	public:
		add(void)
		{
			InitializeComponent();
			//
			//TODO: 在此加入建構函式程式碼
			//
		}
		add(System::ComponentModel::IContainer ^container)
		{
			/// <summary>
			/// Windows.Forms 類別撰寫設計工具支援所需的程式碼
			/// </summary>

			container->Add(this);
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~add()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改這個方法的內容。
		///
		/// </summary>
		void InitializeComponent(void)
		{
			components = gcnew System::ComponentModel::Container();
		}
#pragma endregion
	};
}
