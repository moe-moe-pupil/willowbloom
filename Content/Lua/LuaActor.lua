---------------------------------------------------------------------
-- watchers (C) CompanyName, All Rights Reserved
-- Created by: AuthorName
-- Date: 2020-09-04 20:09:55
---------------------------------------------------------------------

-- To edit this template in: Data/Config/Template.lua
-- To disable this template, check off menuitem: Options-Enable Template File

---@class LuaActor
local actor = {}
local eng = import "Engine"
function actor:ReceiveBeginPlay()
	print("this is a test from no-edit Lua")
	PrintLog("evil is near")
	--print(eng:AddOnScreenDebugMessage("hi"));
end

return actor