#pragma once
#include <EngineCore/EngineCore.h>

// Ό³Έν :
class babaCore : public UserCore
{
public:
	// constrcuter destructer
	babaCore();
	~babaCore();

	// delete Function
	babaCore(const babaCore& _Other) = delete;
	babaCore(babaCore&& _Other) noexcept = delete;
	babaCore& operator=(const babaCore& _Other) = delete;
	babaCore& operator=(babaCore&& _Other) noexcept = delete;

protected:
	void Initialize() override;

private:

};

