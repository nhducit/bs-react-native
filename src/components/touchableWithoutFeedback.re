[@bs.module "react-native"] external view : ReasonReact.reactClass = "TouchableWithoutFeedback";

let make =
    (
      ~accessible=?,
      ~accessibilityComponentType=?,
      ~accessibilityTraits=?,
      ~delayLongPress=?,
      ~delayPressIn=?,
      ~delayPressOut=?,
      ~disabled=?,
      ~hitSlop=?,
      ~onLayout=?,
      ~onLongPress=?,
      ~onPress=?,
      ~onPressIn=?,
      ~onPressOut=?,
      ~pressRetentionOffset=?,
      ~style=?
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Js.Undefined.(
        {
          "accessible": from_opt(UtilsRN.optBoolToOptJsBoolean(accessible)),
          "delayLongPress": from_opt(delayLongPress),
          "delayPressIn": from_opt(delayPressIn),
          "delayPressOut": from_opt(delayPressOut),
          "disabled": from_opt(UtilsRN.optBoolToOptJsBoolean(disabled)),
          "hitSlop": from_opt(hitSlop),
          "onLayout": from_opt(onLayout),
          "onLongPress": from_opt(onLongPress),
          "onPress": from_opt(onPress),
          "onPressIn": from_opt(onPressIn),
          "onPressOut": from_opt(onPressOut),
          "pressRetentionOffset": from_opt(pressRetentionOffset),
          "style": from_opt(style),
          "accessibilityComponentType":
            from_opt(
              UtilsRN.option_map(
                (x) =>
                  switch x {
                  | `none => "none"
                  | `button => "button"
                  | `radiobutton_checked => "radiobutton_checked-none"
                  | `radiobutton_unchecked => "radiobutton_unchecked"
                  },
                accessibilityComponentType
              )
            ),
          "accessibilityTraits":
            from_opt(
              UtilsRN.option_map(
                (traits) => {
                  let to_string =
                    fun
                    | `none => "none"
                    | `button => "button"
                    | `link => "link"
                    | `header => "header"
                    | `search => "search"
                    | `image => "image"
                    | `selected => "selected"
                    | `plays => "plays"
                    | `key => "key"
                    | `text => "text"
                    | `summary => "summary"
                    | `disabled => "disabled"
                    | `frequentUpdates => "frequentUpdates"
                    | `startsMedia => "startsMedia"
                    | `adjustable => "adjustable"
                    | `allowsDirectInteraction => "allowsDirectInteraction"
                    | `pageTurn => "pageTurn";
                  traits |> List.map(to_string) |> Array.of_list
                },
                accessibilityTraits
              )
            )
        }
      )
  );
