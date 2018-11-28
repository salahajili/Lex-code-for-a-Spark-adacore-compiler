package Stack_Package
  with SPARK_Mode
is
   type Element is new Natural;
   type Stack is private;

   function Empty return Stack;
   procedure Push (S : in out Stack; E : Element);
   function Pop (S : in out Stack) return Element;

private
   type Stack is record
      Top : Integer;
      --  ...
   end record;

end Stack_Package;
