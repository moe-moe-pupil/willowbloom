---------------------------------------------------------------------
-- watchers (C) CompanyName, All Rights Reserved
-- Created by: AuthorName
-- Date: 2020-09-05 18:50:15
---------------------------------------------------------------------

-- To edit this template in: Data/Config/Template.lua
-- To disable this template, check off menuitem: Options-Enable Template File
-- call static function of uclass
---@class TestUI
local TestUI={}
function TestUI:Construct()
	print("TestUI Work")
	print(self.mtextbox:SetText("Test UI Work!"))
end
return TestUI
