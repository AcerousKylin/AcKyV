import json

with open("lang\zh_cn.json", 'r', encoding="utf-8") as lang:
    localization = json.load(lang)
    
def get_translation(key, language="zh_cn"):
    return localization[key][language]

language_choice = 'zh_cn'

welcome_text = get_translation('welcome', language_choice)
goodbye_text = get_translation("goodbye", language_choice)