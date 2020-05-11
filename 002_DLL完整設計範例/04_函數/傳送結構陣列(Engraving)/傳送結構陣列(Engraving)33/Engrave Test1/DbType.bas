Attribute VB_Name = "mdlType"
Public Type MYCAM
        C21 As Double   'BlockTop
        C22 As Double   'BlockBottom
        C23 As Double   'BlcokLeft
        C24 As Double   'BlockRight
        C34 As Single  'Rapid Z
        C35 As Single  'Safe Z
        C36 As Single  'First Depth
        C37 As Single  'Last Depth
        C38 As Single  'Unit Depth
        C41 As Integer 'Compension No
        C42 As Integer 'Tool Flag No
        C44 As Long 'Spindle Speed
        C45 As Long 'Cut Feed
        C46 As Long 'Down Feed
        'C58 As Integer 'Oper No *10 + Machine
        C59 As Single  'Material Top
        'C60 As Integer 'Machine Sequence No
        C61 As Integer '
End Type
Public Type MyCAD
        C1 As Long   'Serial No
        C3 As Integer  'DrawType
        C4 As String   'Draw Name
        C5 As Integer  'Layer
        C8 As Integer  'Sequence No
        'C9 As Integer  '
        C10 As Double  'X1   XO
        C11 As Double  'X2   RAD
        C12 As Double  'Y1   YO
        C13 As Double  'Y2   StartAngle
        C14 As Double  '     EndAngle
        C17 As Double   'EntityTop
        C18 As Double   'EntityBottom
        C19 As Double   'EntityLeft
        C20 As Double   'EntityRight
        C25 As Double   'StartX
        C26 As Double   'EndX
        C27 As Double   'StartY
        C28 As Double   'EndY
        C29 As Single   'DrawType
        C30 As String   'Text
        C31 As Double   'Height of Ellipse
        C32 As Single  'Start Z
        C33 As Single  'End Z
        C39 As Integer  'Text Font Bold Operation No
        C40 As Integer  'Text Font Italic Tool No
        C47 As Long   'NURBS   ENumber of Cutting Loop
        C48 As Integer  'NURBS   Bi_Direction
        C49 As Single   'NURBS   CCW
        C50 As String   'TEXT Font Name Tools File Name
        C51 As Single   'NURBS Tool Diameter
        C54 As Single   'NURBS X Position to...
        C55 As Single   'NURBS Y Position to
        C56 As Single  'Relative To Group
        C57 As Boolean 'If Mirror
        CCAM As MYCAM
        
End Type

Public Type MyBlock
        C5 As Integer   'Layer
        C6 As Double 'Single    'Color
        C7 As Long   'Block No
        C8 As String
        C9 As Integer
        C15 As Boolean  'If Delete
        C16 As Boolean  'If Hide
        C21 As Double   'BlockTop
        C22 As Double   'BlockBottom
        C23 As Double   'BlcokLeft
        C24 As Double   'BlockRight
        C43 As Integer  'Working Plane
        C52 As Integer  'Group
        C53 As Integer  'Group Sequence
        C58 As Integer 'Oper No *10 + Machine
        C60 As Integer 'Machine Sequence No
        Child() As MyCAD
        BCatageory As Integer '1  Goemetry: 2  ToolPath: 3  Dimension: 4  Construction: 5  Text
        NoID As Long       '紀錄在個別群組中的位置
        NoKey As String
        NoName As String
        TreeId As Long    '紀錄在樹狀群組中的絕對位置
        IsClose As Boolean
        IsGroup As Boolean
End Type

Public Type EngraveElement
        Type As Long    '1:Line 2:Arc 3:Circle
        CCW As Long      '0:CW 1:CCW
        X1 As Double
        Y1 As Double
        Z1 As Double
        X2 As Double
        Y2 As Double
        Z2 As Double
        
End Type

Public Type EngraveBlock
        Direction As Long  '1:左 2:右 ; 1:內 2:外
        Divide As Long
        Ignore_A As Double
        Cone_A As Double
        F_Depth As Double
        Child() As EngraveElement
End Type
