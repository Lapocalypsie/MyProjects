import { useRouter } from "next/router";
import Editor from "../../../components/Editor";
import ArticleShape from "../../../components/ArticleShape";
import styles from "../../../styles/Editor.module.css";
import PropTypes from "prop-types";

export default function SimplepediaEditor({
  setCurrentArticle,
  currentArticle,
}) {
  const router = useRouter();

  const complete = async (newArticle) => {
    if (newArticle) {
      const response = await fetch(`/api/articles/${newArticle.id}`, {
        method: "PUT",
        body: JSON.stringify(newArticle),
        headers: {
          Accept: "application/json",
          "Content-Type": "application/json",
        },
      });
      const updateArticle = await response.json();
      setCurrentArticle(updateArticle);
      router.push(`/articles/${updateArticle.id}`);
    } else {
      router.back();
    }
  };

  return (
    <div className={styles.Editor}>
      <Editor article={currentArticle} complete={complete} />
    </div>
  );
}

SimplepediaEditor.propTypes = {
  setCurrentArticle: PropTypes.func.isRequired,
  currentArticle: ArticleShape,
};
